#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glColor3f(1,1,1);///白
    glutSolidTeapot(0.3);///身體茶壺
    glPushMatrix();
        glTranslatef(0.4,0,0);///把茶壺掛右邊
        glRotatef(angle,0,0,1);///旋轉
        glTranslatef(0.2,0,0);///軸心放中間
        glColor3f(1,0,0);///紅
        glutSolidTeapot(0.2);///手臂茶壺
        glPushMatrix();
            glTranslatef(0.4,0,0);///把茶壺掛右邊
            glRotatef(angle,0,0,1);///旋轉
            glTranslatef(0.2,0,0);///軸心放中間
            glColor3f(1,0,0);///紅
            glutSolidTeapot(0.2);///手臂茶壺
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.4,0,0);///把茶壺掛右邊
        glRotatef(-angle,0,0,1);///旋轉
        glTranslatef(-0.2,0,0);///軸心放中間
        glColor3f(1,0,0);///紅
        glutSolidTeapot(0.2);///手臂茶壺
        glPushMatrix();
            glTranslatef(-0.4,0,0);///把茶壺掛右邊
            glRotatef(-angle,0,0,1);///旋轉
            glTranslatef(-0.2,0,0);///軸心放中間
            glColor3f(1,0,0);///紅
            glutSolidTeapot(0.2);///手臂茶壺
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

