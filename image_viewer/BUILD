package(default_visibility = ["//visibility:public"])

cc_library(
    name = "image_viewer_lib",
    hdrs = ["image_viewer.h"],
    srcs = ["image_viewer.cpp"],
    deps = ["//common:include", "@sdl2//:shared_lib", "@sdl2_image//:shared_lib"]
)

cc_binary(
    name = "image_viewer",
    srcs = ["image_viewer_main.cpp"],
    deps = [":image_viewer_lib"]
)