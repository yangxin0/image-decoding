cc_library(
    name = "fi_image_decoding_lib",
    srcs = ["fi_image_decoding.cpp", "fi_image_decoding.h"],
    deps = [ "//common:include", "@freeimage//:shared_lib"]
)

cc_binary(
    name = "fi_image_decoding",
    srcs = ["fi_image_decoding_main.cpp"],
    deps = [":fi_image_decoding_lib", "//image_viewer:image_viewer_lib"]
)