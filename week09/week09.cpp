#include <opencv/highgui.h>

void main()
{
    IplImage * img = cvLoadImage("1.png");///Åª¹Ï
    cvShowImage("opencv",img);
    cvWaitKey(0);
}
