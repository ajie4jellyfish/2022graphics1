#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glColor3f(1,1,1);///��
    glutSolidTeapot(0.3);///�������
    glPushMatrix();
        glTranslatef(0.4,0,0);///��������k��
        glRotatef(angle,0,0,1);///����
        glTranslatef(0.2,0,0);///�b�ߩ񤤶�
        glColor3f(1,0,0);///��
        glutSolidTeapot(0.2);///���u����
        glPushMatrix();
            glTranslatef(0.4,0,0);///��������k��
            glRotatef(angle,0,0,1);///����
            glTranslatef(0.2,0,0);///�b�ߩ񤤶�
            glColor3f(1,0,0);///��
            glutSolidTeapot(0.2);///���u����
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.4,0,0);///��������k��
        glRotatef(-angle,0,0,1);///����
        glTranslatef(-0.2,0,0);///�b�ߩ񤤶�
        glColor3f(1,0,0);///��
        glutSolidTeapot(0.2);///���u����
        glPushMatrix();
            glTranslatef(-0.4,0,0);///��������k��
            glRotatef(-angle,0,0,1);///����
            glTranslatef(-0.2,0,0);///�b�ߩ񤤶�
            glColor3f(1,0,0);///��
            glutSolidTeapot(0.2);///���u����
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
    angle+=0.05;
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("Week12 TRT");

    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();
}

