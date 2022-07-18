#include <cstdio>
#include "stb_image_decoding.h"
#include "image_viewer/image_viewer.h"

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "usage: ./stb_image_decoding /path/to/image\n");
        return 1;
    }

    RawImage img;
    int rc = stb_decoding_image(argv[1], &img);
    if (rc != IMG_OK) {
        return 1;
    }

    rendering_init();
    rendering_image("STB", &img);

    return 0;
}