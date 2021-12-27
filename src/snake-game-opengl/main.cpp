/* Code by Ratul Thakur 25th september 2016 edratulthakur@gmail.com */

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
#include <fstream>
#include <string.h>
#include "game.h"

#define ROWS 40.0
#define COLUMNS 40.0

std::ofstream ofile;
std::ifstream ifile;
bool game_over=false;
extern int sDirection;
int score=0;

void init();
void display_callback();
void input_callback(int,int,int);
void reshape_callback(int,int);
void timer_callback(int);

int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowPosition(10,10);
    glutInitWindowSize(600,600);
    glutCreateWindow("SNAKE v1.0");
    glutDisplayFunc(display_callback);
    glutReshapeFunc(reshape_callback);
    glutSpecialFunc(input_callback);
    glutTimerFunc(100,timer_callback,0);
    init();
    glutMainLoop();
    return 0;
}

void init()
{
    glClearColor(0.0,0.0,0.0,0.0);
    initGrid(COLUMNS,ROWS);
}

//Callbacks
void display_callback()
{
    if(game_over)
    {
        ofile.open("score.dat",std::ios::trunc);
        ofile<<score<<std::endl;
        ofile.close();
        ifile.open("score.dat",std::ios::in);
        char a[4];
        ifile>>a;
        std::cout<<a;
        char text[50]= "Your score : ";
        strcat(text,a);
        // MessageBox is only available on Windows, deferring to stdout.
        // MessageBox(NULL,text,"Game Over",0);
        std::cout << text << "Game Over" << std::endl;
        exit(0);
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    draw_grid();
    draw_food();
    draw_snake();
    glutSwapBuffers();
}
void reshape_callback(int w, int h)
{
    glViewport(0,0,(GLfloat)w,GLfloat(h));
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,COLUMNS,0.0,ROWS,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void timer_callback(int)
{
    glutPostRedisplay();
    glutTimerFunc(200,timer_callback,0);
}
void input_callback(int key,int x,int y)
{
    switch(key)
    {
    case GLUT_KEY_UP:
        if(sDirection!=DOWN)
            sDirection=UP;
        break;
    case GLUT_KEY_DOWN:
        if(sDirection!=UP)
            sDirection=DOWN;
        break;
    case GLUT_KEY_RIGHT:
        if(sDirection!=LEFT)
            sDirection=RIGHT;
        break;
    case GLUT_KEY_LEFT:
        if(sDirection!=RIGHT)
            sDirection=LEFT;
        break;
    }
}
