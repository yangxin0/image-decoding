#ifndef _IMAGE_DECODING_H_
#define _IMAGE_DECODING_H_

#include <memory>

enum ImageType { RGB24, BGR24 };

typedef struct {
    ImageType type;
    std::unique_ptr<unsigned char[]> blob;
    int width;
    int height;
} RawImage;

#endif // _IMAGE_DECODING_H_