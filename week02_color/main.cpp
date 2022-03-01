#include <GL/glut.h> ///GLUT外掛,簡化程式

void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0); ///設定色彩
    ///glutSolidTeapot(0.3); ///實心茶壺
    glBegin(GL_POLYGON);
        glColor3f(1,0,0);
        glVertex2f(-1,-1);

        glColor3f(0,1,0);
        glVertex2f(+1,-1);

        glColor3f(0,0,1);
        glVertex2f(0,+1);
    glEnd();
    glutSwapBuffers();///畫好交換出來

}

int main(int argc,char**argv)///main()主函式進階版
{
    glutInit(&argc,argv);///參數給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///雙緩衝區+3D深度功能
    glutCreateWindow("week02程式");
    glutDisplayFunc(display); ///顯示函式
    glutMainLoop();///主要程式迴圈
}
