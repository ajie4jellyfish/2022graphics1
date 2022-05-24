#include <GL/glut.h>
#include <stdio.h>

float angle[20], oldX=0;
int angleID=0;///關節ID
FILE * fout =NULL;
void myWrite(){
    if(fout==NULL)
        fout=fopen("file.txt,","w+");

    for(int i=0;i<20;i++){
        printf("%.1f",angle[i]);
    }
    printf("\n");
    fprintf(fout,"\n");
}
void keyboard(unsigned char key,int x,int y)
{
    if(key=='0') angleID=0;
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
}///更改操作關節
void mouse(int button,int state,int x,int y)
{
    oldX=x;
}
void motion(int x,int y)
{
    angle[angleID]+=(x-oldX);
    myWrite();
    oldX=x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白
    glRectf(0.3,0.5, -0.3,-0.5);///身體
    glPushMatrix();
        glTranslatef(0.3,0.4,0);
        glRotatef(angle[0],0,0,1);
        glTranslatef(-0.3,-0.4,0);
        glColor3f(1,0,0);///紅
        glRectf(0.3,0.5, 0.7,0.3);///右上手臂
        glPushMatrix();
            glTranslatef(0.7,0.4,0);
            glRotatef(angle[1],0,0,1);
            glTranslatef(-0.7,-0.4,0);
            glColor3f(0,1,0);///綠
            glRectf(0.7,0.5, 1.0,0.3);///右下手肘
        glPopMatrix();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.3,0.4,0);
        glRotatef(angle[2],0,0,1);
        glTranslatef(0.3,-0.4,0);
        glColor3f(1,0,0);///紅
        glRectf(-0.3,0.5, -0.7,0.3);///左上手臂
        glPushMatrix();
            glTranslatef(-0.7,0.4,0);
            glRotatef(angle[3],0,0,1);
            glTranslatef(0.7,-0.4,0);
            glColor3f(0,1,0);///綠
            glRectf(-0.7,0.5, -1.0,0.3);///左下手肘
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week13 rect TRT TRT");
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutMainLoop();
}
