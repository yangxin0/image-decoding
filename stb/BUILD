
package(default_visibility = ["//visibility:public"])

cc_library(
    name = "stb_image_decoding_lib",
    srcs = ["stb_image_decoding.cpp", "stb_image_decoding.h", "stb_image.h"],
    deps = ["//common:include"]
)

cc_binary(
    name = "sbt_image_decoding",
    srcs = ["stb_image_decoding_main.cpp"],
    deps = [":stb_image_decoding_lib", "//image_viewer:image_viewer_lib"]
)