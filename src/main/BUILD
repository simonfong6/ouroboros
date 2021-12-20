load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "hello_world_message",
    srcs = ["hello_world_message.cc"],
    hdrs = ["hello_world_message.h"],
)

cc_binary(
    name = "hello_world",
    srcs = ["hello_world.cc"],
    deps = [
        ":hello_world_message",
    ],
)
