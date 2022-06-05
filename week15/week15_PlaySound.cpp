#include <windows.h>
#include <stdio.h>
int main()
{
    printf("PlaySound()\n");
    PlaySound("07042111.wav",NULL,SND_SYNC);
    printf("PlaySound()дзлс\n");
}
