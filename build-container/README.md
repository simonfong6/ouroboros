# Build Container
Container with tools installed for building and running the app.

# Build
```bash
docker-compose build
```

# Push
```bash
bazel run //build-container:docker_push
```

# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

## [2] - 2021-12-26
### Added
- OpenGL
- GLUT
- python3-setup-tools

## [1] - 2021-12-24
### Added
- Bazel
- Buildifier
- Yaml lint
- Clang format
