# Snake Game Ncurses
Snake game using the ncurses library. Most commands assume running on Ubuntu
unless otherwise specified for MacOS.

# Source
I think this is from this youtube video.
- https://www.youtube.com/watch?v=OAv2QsOZ4l4
- Code from: https://github.com/izloop/Snake

# Build
```bash
bazel build //src/snake-game-ncurses:snake
```

# Run
```bash
bazel run //src/snake-game-ncurses:snake
```

# Installing dependencies

## MacOS
```bash
brew install ncurses
```

## Ubuntu
- https://github.com/ourarash/ncurses_bazel
```bash
apt-get install -y libncurses5-dev libncursesw5-dev
```
