// Programmer: Mihalis Tsoukalos
// Date: Wednesday 04 June 2014
//
// A simple OpenGL program that draws a triangle.

#include "GL/freeglut.h"
#include "GL/gl.h"

void drawTriangle()
{
    glClearColor(0.2, 0.1, 0.4, 0.4);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.5, 1.0, 0.5);
    //glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

        //glBegin(GL_TRIANGLES);
        glBegin(GL_TRIANGLES);
                glVertex3f(-0.7, 0.2, 0);
                glVertex3f(-0.2, 0.2, 0);
                glVertex3f(-0.5, -0.5, 0);
        glEnd();
        glBegin(GL_QUADS);
                glVertex3f(-0.1, 0.7, 0);
                glVertex3f(0.7, 0.7, 0);
                glVertex3f(0.7, -0.1, 0);
                glVertex3f(-0.1, -0.1, 0);
        glEnd();
#if 1
		glBegin(GL_QUAD_STRIP);
                glVertex3f(-0.1, -0.2, 0);
                glVertex3f(0.1, -0.2, 0);
                glVertex3f(-0.3, -0.4, 0);
                glVertex3f(0.3, -0.4, 0);
                glVertex3f(-0.3, -0.7, 0);
                glVertex3f(0.3, -0.7, 0);
                glVertex3f(-0.1, -0.9, 0);
                glVertex3f(0.1, -0.9, 0);
        glEnd();
#endif
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("OpenGL - Creating a triangle");
    glutDisplayFunc(drawTriangle);
    glutMainLoop();
    return 0;
}
