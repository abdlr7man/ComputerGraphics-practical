#include <glut.h>

void display(){
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,1,1);
    glEnable(GL_POINT_SMOOTH);
    glPointSize(15);
    glBegin(GL_POINTS);
    glVertex2f(30,30);
    glEnd();
    glFlush();
}
void main (){
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("Point");
    gluOrtho2D(0,200,0,200);
    glutDisplayFunc(display);
    glutMainLLoop();
