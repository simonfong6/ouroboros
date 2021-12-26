load("@rules_cc//cc:defs.bzl", "cc_binary")

# Platform dependent build: https://stackoverflow.com/questions/45186465/platform-dependent-linker-flags-in-bazel-for-glut/45217333
config_setting(
    name = "darwin",
    constraint_values = ["@bazel_tools//platforms:osx"],
)

config_setting(
    name = "linux",
    constraint_values = ["@bazel_tools//platforms:linux"],
)

cc_binary(
    name = "snake",
    srcs = ["main.cc"],
    # Added `-lgpm` since it complained otherwise.
    # https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=900839
    linkopts = select({
        ":darwin": [
        ],
        ":linux": ["-lgpm"],
    }),
    deps = select({
        ":darwin": ["@ncurses-mac//:main"],
        ":linux": ["@ncurses//:main"],
    }),
)
