#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h"///�b�M�~�ؿ���
GLMmodel * pmodel = NULL ;///���СA����ҫ��A�O�ū���
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename);
    cvCvtColor(img,img, CV_BGR2RGB);
    glEnable(GL_TEXTURE_2D);
    GLuint id;
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    if( pmodel == NULL){
        pmodel=glmReadOBJ("data/body.obj");///Ū�ҫ�
        glmUnitize(pmodel);///����Unit���j�p
        glmFacetNormals(pmodel);///���s�p��ҫ������k�V�q
        glmVertexNormals(pmodel,90);///���s�p��ҫ����I���k�V�q
    }
    glPushMatrix();
        glRotatef(angle,0,1,0);
        glmDraw(pmodel,GLM_TEXTURE);///�ҫ��e�K��
    glPopMatrix();

    glutSwapBuffers();
    angle+=0.8;
}

int main(int argc,char** argv)
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week11 gundam");

    glutIdleFunc(display);
    glutDisplayFunc(display);
    myTexture("data/Diffuse.jpg");
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}
