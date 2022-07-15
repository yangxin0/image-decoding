#include <cstdio>
#include "FreeImage.h"
#include "fi_image_decoding.h"

int fi_decode_image(const char *filename)
{
    FREE_IMAGE_FORMAT type;
    FIBITMAP *img;

    type = FreeImage_GetFileType(filename);
    printf("image format is: %d\n", type);
    img = FreeImage_Load(type, filename);
    if (img == nullptr) {
        printf("load image failed\n");
        return 1;
    }

    RGBQUAD rgb;
    FreeImage_GetPixelColor(img, 0, 0, &rgb);
    printf("pxiel color at (0, 0): B %d, G %d, R %d\n", rgb.rgbBlue, rgb.rgbGreen, rgb.rgbRed);

    int width = FreeImage_GetWidth(img);
    int height = FreeImage_GetHeight(img);
    int pitch = FreeImage_GetPitch(img);
    int bpp = FreeImage_GetBPP(img);
    printf("image: width %d, height %d, pitch %d, bpp %d\n", width, height, pitch, bpp);

    BYTE *raw = FreeImage_GetBits(img);
    printf("raw bits: %d, %d, %d\n", raw[0], raw[1], raw[2]);

    FreeImage_Unload(img);

    return 0;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: ./fi-image-decoding /path/to/image\n");
        return 1;
    }

    return fi_decode_image(argv[1]);
}