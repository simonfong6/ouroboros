load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_test(
    name = "hello_world_message_unittest",
    size = "small",
    srcs = ["hello_world_message_unittest.cc"],
    deps = [
        ":hello_world_message",
        "@com_google_googletest//:gtest_main",
    ],
)

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
