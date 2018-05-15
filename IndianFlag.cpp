// Programmer: Mihalis Tsoukalos
// Date: Wednesday 04 June 2014
//
// A simple OpenGL program that draws a triangle.

/* Compile with "gcc IndianFlag.cpp -lGL -lglut -lm" command */

#include "GL/freeglut.h"
#include "GL/gl.h"
#include <stdio.h>
#include <cmath>

#define PI 3.14
using namespace std;
static int a = 0;
void DrawStar() 
{
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_TRIANGLE_FAN);
	//All triangles fan out starting with this point
	glVertex2f (0.5,0.5);
	for (int i = 0; i <=360; i++)
	{				
		if(i % 7 == 0)
		{
			if(a == 1)
				a = 0;
			else
				a = 1;
		}
		if(a == 0)
			glColor3f(0.0,0.0,1.0);
		else
			glColor3f(1.0,1.0,1.0);

		glVertex2f(0.1*cos(i*PI/180)+0.5, 0.15*sin(i*PI/180)+0.5);
	}
	glEnd();
	return;
}

void DrawStripes() 
{
		glColor3f(18.0/255.0,136.0/255.0, 7.0/255.0);
		glBegin(GL_QUADS);
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(1.0, 0.0, 0.0);
			glVertex3f(1.0, 1.0/3.0, 0.0);
			glVertex3f(0.0, 1.0/3.0, 0.0);
		glEnd();
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_QUADS);
			glVertex3f(0.0, 1.0/3.0, 0.0);
			glVertex3f(1.0, 1.0/3.0, 0.0);
			glVertex3f(1.0, 2.0/3.0, 0.0);
			glVertex3f(0.0, 2.0/3.0, 0.0);
		glEnd();
		glColor3f(1.0, 153.0/255.0, 51.0/255.0);
		glBegin(GL_QUADS);
			glVertex3f(0.0, 2.0/3.0, 0.0);
			glVertex3f(1.0, 2.0/3.0, 0.0);
			glVertex3f(1.0, 3.0/3.0, 0.0);
			glVertex3f(0.0, 3.0/3.0, 0.0);
		glEnd();
}

void DrawPole()
{
#if 0
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_QUAD_STRIP);
		glVertex3f(-0.12, -1.0, 0.0);
		glVertex3f(0.1, -1.0, 0.0);
		glVertex3f(-0.12, -0.9, 0.0);
		glVertex3f(0.1,-0.9, 0.0);
		glVertex3f(-0.02, -0.8, 0.0);
		glVertex3f(0.0,-0.8, 0.0);
		glVertex3f(0.0,1.0, 0.0);
		glVertex3f(-0.02, 1.0, 0.0);
	glEnd();
#else
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_QUADS);
		glVertex3f(-0.02, -0.8, 0.0);
		glVertex3f(0.0, -0.8, 0.0);
		glVertex3f(0.0,1.0, 0.0);
		glVertex3f(-0.02, 1.0, 0.0);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-0.07, -0.9, 0.0);
		glVertex3f(0.05, -0.9, 0.0);
		glVertex3f(0.05,-0.8, 0.0);
		glVertex3f(-0.07, -0.8, 0.0);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-0.12, -1.0, 0.0);
		glVertex3f(0.1, -1.0, 0.0);
		glVertex3f(0.1,-0.9, 0.0);
		glVertex3f(-0.12, -0.9, 0.0);
	glEnd();
#endif
}

void drawTriangle()
{
	glClear(GL_COLOR_BUFFER_BIT);
	DrawPole();
	DrawStripes();
	DrawStar();
	glFlush();
}

void Initialize() 
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(950, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL - Creating a Flag");
    Initialize();
    glutDisplayFunc(drawTriangle);
    glutMainLoop();
    return 0;
}
