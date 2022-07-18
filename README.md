# Image Decoding Tools

This repo contains freeimage and stb image decoding samples and should be used for
debuging decoding problems. Take your risk when use these decoding samples in production.

### How to start

1. Install the required dependency
```shell
brew install pkg-config
brew install sdl2 sdl2_image freeimage
```

2. Build with bazel
```shell
cd /path/to/repo
# build all the targets
bazel build '...'
```
This commands will build all the targets in repo and the outputs reside in 
```bazel-bin```.


