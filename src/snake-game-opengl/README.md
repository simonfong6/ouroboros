# Snake Game OpenGL
Snake game in OpenGL.

# Source
- [OpenGL & C++ game programming tutorial ( 2D ) | PART 1 | Creating a snake Game](https://www.youtube.com/watch?v=6Miai_t_ksw)
  - [The Pentamollis Project](https://www.youtube.com/channel/UCjsG1HaLXHytO8bG3_TIakQ)
- [Google Drive Rar from Video](https://drive.google.com/file/d/1p9oB3vkXplnkYxN5wK2YV1QZmRwqn7eJ/view)
With some minor modifications to work on Mac/Linux. Including:
- Bazel build file.
- Removing `MessageBox` since it is Windows specific. See [forum](https://gamedev.net/forums/topic/505666-messagebox-with-glut/505666/).
- Adding `string.h` for `strcat` according to the [reference](https://www.cplusplus.com/reference/cstring/strcat/).
- Mac headers in conditional.
- Removed various files that I assume are part of the 
# Build
```bash
bazel build //src/snake-game-opengl:main
```

# Run
```bash
bazel run //src/snake-game-opengl:main
```
