/*
Code from:
- https://www.badprog.com/c-opengl-hello-world
- https://github.com/bazelbuild/bazel/issues/85
*/
#ifdef __APPLE__
/* Defined before OpenGL and GLUT includes to avoid deprecation messages
https://stackoverflow.com/questions/53562228/silencing-opengl-warnings-on-macos-mojave/55644380
*/
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif

#include <iostream>

#include "src/opengl-helloworld/hello-lib.h"

void displayMe(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);
  glVertex3f(0.0, 0.0, 0.0);
  glVertex3f(0.5, 0.0, 0.0);
  glVertex3f(0.5, 0.5, 0.0);
  glVertex3f(0.0, 0.5, 0.0);
  glEnd();
  glFlush();
}

int main(int argc, char** argv) {
  hello::HelloLib hello_lib = hello::HelloLib("Hello ");

  hello_lib.greet("World");

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE);
  glutInitWindowSize(300, 300);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Hello world from Badprog.com :D");
  glutDisplayFunc(displayMe);
  glutMainLoop();
  return 0;
}
