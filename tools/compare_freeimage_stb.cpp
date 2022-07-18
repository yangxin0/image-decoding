#include <cassert>
#include <cstdio>
#include "common/image_decoding.h"
#include "freeimage/fi_image_decoding.h"
#include "stb/stb_image_decoding.h"

#define RGB_R(p) (*(p))
#define RGB_G(p) (*(p+1))
#define RGB_B(p) (*(p+2))

#define BGR_R(p) (*(p+2))
#define BGR_G(p) (*(p+1))
#define BGR_B(p) (*(p))

int main(int argc, char *argv[]) 
{
    if (argc < 2) {
        fprintf(stderr, "usage: ./compare_freeimage_stb /path/to/image\n");
        return 1;
    }
    RawImage fimg;
    RawImage simg;

    fi_decode_image(argv[1], &fimg);
    stb_decoding_image(argv[1], &simg);

    assert(fimg.type == IMG_BGR24 && simg.type == IMG_RGB24);

    if (fimg.size != simg.size) {
        fprintf(stderr, "size mismatch: freeimage %d, stb %d\n", fimg.size, simg.size);
        return 1;
    }

    if (fimg.width != simg.width || fimg.height != simg.height) {
        fprintf(stderr, "width or height mismatch: freeimage(w%d, h%d) stb(w%d, h%d)\n",
                fimg.width, fimg.height, simg.width, simg.height);
      return 1;
    }

    unsigned char *f, *s;
    f = fimg.blob.get();
    s = simg.blob.get();
    int mismatch = 0;
    // 3 comp
    for (int i = 0; i < fimg.size; i += 3) {
        int f_R, f_G, f_B;
        f_R = BGR_R(f+i);
        f_G = BGR_G(f+i);
        f_B = BGR_B(f+i);
        int s_R, s_G, s_B;
        s_R = RGB_R(s+i);
        s_G = RGB_G(s+i);
        s_B = RGB_B(s+i);
        if (f_R != s_R || f_G != s_G || f_B != s_B) {
            fprintf(stderr, "pixel mismatch @ (%d): (freeimage, stb) => R(%d, %d) G(%d, %d) B(%d, %d)\n",
                    i, f_R, s_R, f_G, s_G, f_B, s_B);
            mismatch = 1;
        }
    }

    if (!mismatch) {
        printf("<<freeimage and stb decode the same>>\n");
    }

    return mismatch;
}