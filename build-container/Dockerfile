# https://hub.docker.com/_/ubuntu
FROM ubuntu:bionic-20210930

# Working directory to leave docker image build artifacts.
WORKDIR /build

# Pin versions in apt get install.
# https://unix.stackexchange.com/questions/6284/how-do-i-check-package-version-using-apt-get-aptitude
# wget: Download files.
# git: Clone repos to install tools.
# build-essential: gcc for building with bazel.
# python3: Install latest yamllint.
# python3-pip: Install latest yamllint.
# python3-setuptools: Install python packages tooling. (https://stackoverflow.com/questions/14426491/python-3-importerror-no-module-named-setuptools)
# clang-format-10: Format and lint c++ code.
# libglu1-mesa-dev: OpenGL + GLUT (http://www.codebind.com/linux-tutorials/install-opengl-ubuntu-linux/)
# freeglut3-dev: OpenGL + GLUT
# mesa-common-dev: OpenGL + GLUT
# libncurses5-dev: ncurses for snake.
# libncursesw5-dev: ncurses for snake.
# libgpm-dev: Static compilation for ncurses.
RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get install -y \
        --no-install-recommends \
        wget=1.19.4-1ubuntu2.2 \
        git=1:2.17.1-1ubuntu0.9 \
        build-essential=12.4ubuntu1 \
        python3=3.6.7-1~18.04 \
        python3-pip=9.0.1-2.3~ubuntu1.18.04.5 \
        python3-setuptools=39.0.1-2 \
        clang-format-10=1:10.0.0-4ubuntu1~18.04.2 \
        libglu1-mesa-dev=9.0.0-2.1build1 \
        freeglut3-dev=2.8.1-3 \
        mesa-common-dev=20.0.8-0ubuntu1~18.04.1 \
        libncurses5-dev=6.1-1ubuntu1.18.04 \
        libncursesw5-dev=6.1-1ubuntu1.18.04 \
        libgpm-dev=1.20.7-5 \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Install bazel via bazelisk.
# https://github.com/bazelbuild/bazelisk/blob/master/README.md
# Run bazel once to download it.
RUN wget \
    --progress=dot:giga \
    https://github.com/bazelbuild/bazelisk/releases/download/v1.11.0/bazelisk-linux-amd64 \
    -O /usr/local/bin/bazel && \
    chmod +x /usr/local/bin/bazel && \
    bazel --version

# Install go.
# https://go.dev/doc/install
RUN wget \
    --progress=dot:giga \
    https://go.dev/dl/go1.17.5.linux-amd64.tar.gz && \
    rm -rf /usr/local/go && \
    tar -C /usr/local -xzf go1.17.5.linux-amd64.tar.gz

# Install hadolint to lint Dockerfile.
# https://github.com/hadolint/hadolint
RUN wget \
    --progress=dot:giga \
    https://github.com/hadolint/hadolint/releases/download/v2.8.0/hadolint-Linux-x86_64 \
    -O /usr/local/bin/hadolint && \
    chmod +x /usr/local/bin/hadolint

# Add go to the path.
ENV PATH=$PATH:/usr/local/go/bin

# Install buildifier.
# https://github.com/bazelbuild/buildtools/blob/master/buildifier/README.md
# Ignoring warning about `cd` since there is no good workaround without adding
# another layer.
# hadolint ignore=DL3003
RUN git clone https://github.com/bazelbuild/buildtools.git && \
    (cd buildtools && bazel build //buildifier) && \ 
    cp buildtools/bazel-bin/buildifier/buildifier_/buildifier /usr/local/bin/ && \
    rm -rf buildtools

# Install yamllint.
# https://yamllint.readthedocs.io/en/v1.26.3/quickstart.html
RUN pip3 install \
    --no-cache-dir \
    yamllint==1.26.3

WORKDIR /workspace

# Clean up artifacts in build directory.
RUN rm -rf /build
