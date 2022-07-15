#include <cstdio>
#include <cstring>
#include "FreeImage.h"
#include "fi_image_decoding.h"


int fi_decode_core(const char *filename, FIBITMAP **map)
{
    FREE_IMAGE_FORMAT type;
    FIBITMAP *img;

    type = FreeImage_GetFileType(filename);
    if (type == FIF_UNKNOWN) {
        return IMG_ERR_FTYPE;
    }
    printf("freeimage: file format=%d\n", type);

    img = FreeImage_Load(type, filename);
    if (img == nullptr) {
        fprintf(stderr, "freeimage: load image failed\n");
        return IMG_ERR_BLOB;
    }

    int width = FreeImage_GetWidth(img);
    int height = FreeImage_GetHeight(img);
    int pitch = FreeImage_GetPitch(img);
    int bpp = FreeImage_GetBPP(img);
    printf("freeimage: width %d, height %d, pitch %d, bpp %d\n", width, height, pitch, bpp);

    *map = img;

    return IMG_OK;
}


int fi_decode_image(const char *filename, RawImage *img)
{
    int rc;
    FIBITMAP *map;

    if (filename == nullptr || img == nullptr) {
        fprintf(stderr, "freeimage: invalid parameters\n");
        return IMG_ERR;
    }

    // decode image
    rc = fi_decode_core(filename, &map);
    if (rc != IMG_OK) {
        return rc;
    }

    // convert to 24bit
    FIBITMAP *tmp = FreeImage_ConvertTo24Bits(map);
    FreeImage_Unload(map);
    if (tmp == nullptr) {
        fprintf(stderr, "freeimage: convert 24bit image failed\n");
        return IMG_ERR;
    } else {
        map = tmp;
    }

    int width = FreeImage_GetWidth(map);
    int height = FreeImage_GetHeight(map);
    int pitch = FreeImage_GetPitch(map);
    int bpp = FreeImage_GetBPP(map);

    int stride =  (bpp * width + 7) / 8;
    unsigned char *blob = FreeImage_GetBits(map);
    if (blob == nullptr) {
        fprintf(stderr, "freeimage: get bits failed\n");
        FreeImage_Unload(map);
        return IMG_ERR;
    }

    img->width = width;
    img->height = height;
    img->stride = stride;
    img->size = height * stride;
    img->blob.reset(new unsigned char[stride * height]);
    img->type = IMG_BGR24;

    // fill blob from bitmap
    unsigned char *data = img->blob.get() + height * stride;
    for (int i = 0; i < height; i++) {
        data -= stride;
        memcpy(data, blob, stride);
        // pitch is the linesize of image in freeimage
        blob += pitch;
    }

    FreeImage_Unload(map);
    
    return IMG_OK;
}

