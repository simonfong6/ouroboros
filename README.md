# Ouroboros
Possibly a snake game?

# Requirements
- [Bazel](https://docs.bazel.build/versions/main/install.html)

# How to Run
In `src/`
```bash
bazel build //main:hello_world
```
# Test
In `src/`
```bash
bazel test --test_output=all //main:hello_world_message_unittest
```
