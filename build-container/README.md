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
