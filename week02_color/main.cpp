#include <GL/glut.h> ///GLUT�~��,²�Ƶ{��

void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0); ///�]�w��m
    ///glutSolidTeapot(0.3); ///��߯���
    glBegin(GL_POLYGON);
        glColor3f(1,0,0);
        glVertex2f(-1,-1);

        glColor3f(0,1,0);
        glVertex2f(+1,-1);

        glColor3f(0,0,1);
        glVertex2f(0,+1);
    glEnd();
    glutSwapBuffers();///�e�n�洫�X��

}

int main(int argc,char**argv)///main()�D�禡�i����
{
    glutInit(&argc,argv);///�ѼƵ�glutInit��l��
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///���w�İ�+3D�`�ץ\��
    glutCreateWindow("week02�{��");
    glutDisplayFunc(display); ///��ܨ禡
    glutMainLoop();///�D�n�{���j��
}
