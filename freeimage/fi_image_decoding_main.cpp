#include <cstdio>
#include "fi_image_decoding.h"
#include "image_viewer/image_viewer.h"

int main(int argc, char *argv[])
{
    int rc;
    RawImage img;

    if (argc < 2) {
        printf("usage: ./fi_image_decode_main /path/to/image\n");
        return 1;
    }

    rc = fi_decode_image(argv[1], &img);
    if (rc != IMG_OK) {
        return 1;
    }

    printf("main: width %d, height %d, format %d\n", img.width, img.height, img.type);

    rendering_init();
    rendering_image("freeimage", &img);

    return 0;
}