#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "image_viewer.h"

void usage()
{
    fprintf(stderr, "./image_viewer BGR24/RGB24 width height stride blob_file\n");
    exit(1);
}

int main(int argc, char *argv[])
{
    if (argc < 6) {
        usage();
    }

    const char *type = argv[1];
    int width, height, stride;
    sscanf(argv[2], "%d", &width);
    sscanf(argv[3], "%d", &height);
    sscanf(argv[4], "%d", &stride);
    const char *blob = argv[5];

    RawImage img;
    if (!strcmp(type, "BGR24")) {
        img.type = IMG_BGR24;
    } else if (!strcmp(type, "RGB24")) {
        img.type = IMG_RGB24;
    } else {
        usage();
    }

    img.width = width;
    img.height = height;
    img.stride = stride * width;
    img.size = img.stride * height;
    img.blob.reset(new unsigned char[img.size]);

    FILE *fin = fopen(blob, "rb");
    if (fin == nullptr) {
        fprintf(stderr, "blob file not found\n");
        usage();
    }
    fread(img.blob.get(), 1, img.size, fin);
    fclose(fin);

    rendering_init();
    rendering_image(type, &img);

    return 0;
}