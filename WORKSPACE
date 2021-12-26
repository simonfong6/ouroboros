load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "com_google_googletest",
    strip_prefix = "googletest-609281088cfefc76f9d0ce82e1ff6c30cc3591e5",
    urls = ["https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip"],
)

# Use this for Ubuntu.
# https://github.com/ourarash/ncurses_bazel
new_local_repository(
    name = "ncurses",
    build_file = "ncurses.BUILD",
    path = "/usr/",
)

# Install with homebrew on Mac.
# https://github.com/ourarash/ncurses_bazel
new_local_repository(
    name = "ncurses-mac",
    build_file = "ncurses-mac.BUILD",
    path = "/usr/local/opt/ncurses",
)
