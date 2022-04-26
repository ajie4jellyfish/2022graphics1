#include <GL/glut.h>
#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * pmodel=NULL;
///GLUquadric * sphere =NULL;///指標，指到二次曲面
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
float angle=0;///旋轉角度
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
       if(pmodel== NULL){
        pmodel= glmRead("data/Gundam.obj");
        glmUnitize(pmodle);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel,90);
       }
        glmPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
    angle+=0.1;///每次display()加1度
}

int main(int argc,char** argv)
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week10 texture background");

    glEnable(GL_DEPTH_TEST);///開3D測試
    glutIdleFunc(display);///有空idle 呼叫display()
    glutDisplayFunc(display);
    myTexture("data/Diffuse.jpg");

    ///sphere=gluNewQuadric();

    glutMainLoop();
}

