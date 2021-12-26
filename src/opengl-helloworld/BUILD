load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

# Platform dependent build: https://stackoverflow.com/questions/45186465/platform-dependent-linker-flags-in-bazel-for-glut/45217333
config_setting(
    name = "darwin",
    constraint_values = ["@bazel_tools//platforms:osx"],
)

config_setting(
    name = "linux",
    constraint_values = ["@bazel_tools//platforms:linux"],
)

cc_library(
    name = "hello-lib",
    srcs = ["hello-lib.cc"],
    hdrs = ["hello-lib.h"],
    linkopts = select({
        ":darwin": [
            "-framework OpenGL",
            "-framework GLUT",
        ],
        ":linux": [
            "-lGL",
            "-lGLU",
            "-lglut",
        ],
    }),
)

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [
        ":hello-lib",
    ],
)
