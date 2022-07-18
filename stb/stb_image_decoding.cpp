#include "stb_image_decoding.h"
#include <cassert>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <cstdio>
#include <cstring>

int stb_decoding_image(const char *filename, RawImage *img)
{
    int width, height, comp;
    if (img == nullptr) {
        fprintf(stderr, "stb: invalid parameters\n");
        return IMG_ERR;
    }

    // drop alpha channel
    unsigned char *pxiels = stbi_load(filename, &width, &height, &comp, 3);
    if (pxiels == nullptr) {
        fprintf(stderr, "stb: decoding from file failed, %s\n", stbi_failure_reason());
        return IMG_ERR_BLOB;
    }
    assert(comp == 3);

    printf("stb: width %d, height %d, comp %d\n", width, height, comp);

    img->width = width;
    img->height = height;
    img->stride = width * comp;
    img->size = width * height * comp;
    img->type = IMG_RGB24;
    img->blob.reset(new unsigned char[img->size]);
    memcpy(img->blob.get(), pxiels, img->size);

    stbi_image_free(pxiels);

    return IMG_OK;
}