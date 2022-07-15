#ifndef _IMAGE_DECODING_H_
#define _IMAGE_DECODING_H_

#include <memory>

#define IMG_OK 0
#define IMG_ERR -1
#define IMG_ERR_FTYPE -2
#define IMG_ERR_BLOB -3


enum ImageType { IMG_RGB24, IMG_BGR24 };

typedef struct {
    ImageType type;
    std::unique_ptr<unsigned char[]> blob;
    int width;
    int height;
    int stride; // linesize of image
    int size;
} RawImage;

#endif // _IMAGE_DECODING_H_