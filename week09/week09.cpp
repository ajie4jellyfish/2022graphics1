#include <opencv/highgui.h>

void main()
{
    IplImage * img = cvLoadImage("1.png");///Ū��
    cvShowImage("opencv",img);
    cvWaitKey(0);
}
