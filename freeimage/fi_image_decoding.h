#ifndef _FI_IMAGE_DECODING_H_
#define _FI_IMAGE_DECODING_H_
#include <FreeImage.h>
#include "common/image_decoding.h"

int fi_decode_image(const char *filename, RawImage *img);

#endif