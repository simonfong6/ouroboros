# Open GL Hello World
Simple hello world that imports a library and draws a simple rectangle in a
window. Tested on OpenGL with Bazel on Mac.

# Build
```bash
bazel build //src/opengl-helloworld:main
```

# Run
```bash
bazel run //src/opengl-helloworld:main
```

# Forward Display from Container
Allow the docker container to use the host Mac to display the OpenGL window.
- https://medium.com/@mreichelt/how-to-show-x11-windows-within-docker-on-mac-50759f4b65cb
- https://unix.stackexchange.com/questions/429760/opengl-rendering-with-x11-forwarding

# Start XQuartz
Start by running the desktop application.

## Read Xquartz settings
```bash
defaults read org.xquartz.X11
```

## Enable IGLX Xquartz settings for OpenGL
```bash
defaults write org.xquartz.X11  enable_iglx -bool true
```
You will *need* to restart the computer for this to take effect.

## Allow connections to Xquartz
```bash
xhost + 127.0.0.1
```

## Docker Container Display
Set the following in your docker container.
```bash
DISPLAY=host.docker.internal:0
```

## Test Display Forwarding
This command should now run properly and be visible on the host display.
```bash
bazel run //src/opengl-helloworld:main
```

- TODO: How to install OpenGL on Mac.
