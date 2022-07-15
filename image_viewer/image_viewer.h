#ifndef _IMAGE_VIEWER_H_
#define _IMAGE_VIEWER_H_

#include "common/image_decoding.h"

// Little endian
#define R 0x000000ff
#define G 0x0000ff00
#define B 0x00ff0000
#define A 0xff000000

void rendering_init();
int rendering_image(const char *caption, RawImage *img);

#endif // _IMAGE_VIEWER_H_