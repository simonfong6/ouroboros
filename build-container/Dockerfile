# https://hub.docker.com/_/ubuntu
FROM ubuntu:bionic-20210930

# Working directory to leave docker image build artifacts.
WORKDIR /build

# wget: Download files.
# git: Clone repos to install tools.
# build-essential: gcc for building with bazel.
# python3: Install latest yamllint.
# python3-pip: Install latest yamllint.
# clang-format-10: Format and lint c++ code.
RUN apt update -y && \
    apt upgrade -y && \
    apt install -y \
    wget \
    git \
    build-essential \
    python3 \
    python3-pip \
    clang-format-10

# Install bazel via bazelisk.
# https://github.com/bazelbuild/bazelisk/blob/master/README.md
# Run bazel once to download it.
RUN wget \
    https://github.com/bazelbuild/bazelisk/releases/download/v1.11.0/bazelisk-linux-amd64 \
    -O /usr/local/bin/bazel && \
    chmod +x /usr/local/bin/bazel && \
    bazel --version

# Install go.
# https://go.dev/doc/install
RUN wget https://go.dev/dl/go1.17.5.linux-amd64.tar.gz && \
    rm -rf /usr/local/go && \
    tar -C /usr/local -xzf go1.17.5.linux-amd64.tar.gz

# Install hadolint to lint Dockerfile.
# https://github.com/hadolint/hadolint
RUN wget \
    https://github.com/hadolint/hadolint/releases/download/v2.8.0/hadolint-Linux-x86_64 \
    -O /usr/local/bin/hadolint && \
    chmod +x /usr/local/bin/hadolint

# Add go to the path.
ENV PATH=$PATH:/usr/local/go/bin

# Install buildifier.
# https://github.com/bazelbuild/buildtools/blob/master/buildifier/README.md
RUN git clone https://github.com/bazelbuild/buildtools.git && \
    cd buildtools && \
    bazel build //buildifier && \
    cp bazel-bin/buildifier/buildifier_/buildifier /usr/local/bin/

# Install yamllint.
# https://yamllint.readthedocs.io/en/v1.26.3/quickstart.html
RUN pip3 install yamllint

# Clean up artifacts in build directory.
RUN rm -rf /build
