#include <GL/glut.h>
float mouseX=0,mouseY=0;
void myTeapot(float x,float y)

{

    glPushMatrix();///�ƥ��x�}

        glTranslatef(x,y,0);

        glColor3f(1,1,0);///����

        glutSolidTeapot(0.3);///����

    glPopMatrix();///�٭�x�}

}

void display()

{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    myTeapot((mouseX-150)/150.0,-(mouseY-150)/150.0);

    glutSwapBuffers();

}
void mouse(int button,int state,int x,int y)
{
    mouseX=x; mouseY=y;
}

int main(int argc,char** argv)

{

    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);

    glutCreateWindow("week03 ����");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();

}