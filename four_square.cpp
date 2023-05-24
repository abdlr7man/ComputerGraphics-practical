#include <GL/glut.h>
float p1=125,p2=125;

void display(){
    glClearColor(0,1,1,0);
    glClear(GL_COLOR_BUFFER_BIT);
    bool c=0;

    for (int y=50;y<=400;y+=50){
        for (int x=50;x<=400;x+=50){
            glBegin(GL_POLYGON);
            glColor3f(c,c,c);
            glVertex2f(50+x,50+y);
            glVertex2f(100+x,50+y);
            glVertex2f(100+x,100+y);
            glVertex2f(50+x,100+y);
            glEnd();
            c=!c;
        }
        c=!c;
    }

    glPointSize(65);
    glBegin(GL_POINTS);
    glColor3f(1,0.5,0.9);
    glVertex2f(p1,p2);
    glEnd();
    glFlush();
    glutPostRedisplay();
}

void move_up(){
    if (p2<450)
        p2+=50;
}

void move_down(){
    if (p2>150)
        p2-=50;
}

void move_left(){
    if (p1>150)
        p1-=50;
}

void move_right(){
    if (p1<450)
        p1+=50;
}

void keyboard(int key,int x,int y){
    switch(key){
    case 27:exit(0); break;
    case GLUT_KEY_UP:move_up(); break;
    case GLUT_KEY_DOWN:move_down() ;break;
    case GLUT_KEY_LEFT:move_left() ;break;
    case GLUT_KEY_RIGHT:move_right() ;break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitWindowPosition(100,0);
    glutInitWindowSize(900,900);
    glutCreateWindow("Chess Board With Pointer");
    gluOrtho2D(0,600,0,600);
    glutDisplayFunc(display);
    glutSpecialFunc(keyboard);
    glutMainLoop();
    return 0;
}
