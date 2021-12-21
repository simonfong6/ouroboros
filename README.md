# Ouroboros
Possibly a snake game?

# Requirements
- [Bazel](https://docs.bazel.build/versions/main/install.html)

# Build
In `src/`
```bash
bazel build //main:hello_world
```

# Run
In `src/`
```bash
bazel-bin/main/hello_world
```

# Test
In `src/`
```bash
bazel test --test_output=all //main:hello_world_message_unittest
```

# Build Container
```bash
docker-compose -f build-container/docker-compose.yml run build-container
```
