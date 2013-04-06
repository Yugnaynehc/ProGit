#include <windows.h>
#include <stdlib.h>
#include "mmsystem.h"
#pragma comment(lib, "winmm.lib")
int main()
{
    do
	{
        PlaySound("D:\\spring.wav", NULL, SND_FILENAME);
    } while (1);
}
