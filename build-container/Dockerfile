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
# clang-format-10: Format and lint c++ code.
RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get install -y \
        --no-install-recommends \
        wget=1.19.4-1ubuntu2.2 \
        git=1:2.17.1-1ubuntu0.9 \
        build-essential=12.4ubuntu1 \
        python3=3.6.7-1~18.04 \
        python3-pip=9.0.1-2.3~ubuntu1.18.04.5 \
        clang-format-10=1:10.0.0-4ubuntu1~18.04.2 \
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
RUN git clone https://github.com/bazelbuild/buildtools.git && \
    bazel build \
        --package_path buildtools \
        //buildifier && \
    cp buildtools/bazel-bin/buildifier/buildifier_/buildifier /usr/local/bin/

# Install yamllint.
# https://yamllint.readthedocs.io/en/v1.26.3/quickstart.html
RUN pip3 install \
    --no-cache-dir \
    yamllint==1.26.3

WORKDIR /workspace

# Clean up artifacts in build directory.
RUN rm -rf /build
