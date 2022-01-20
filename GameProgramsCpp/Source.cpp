#include "SSDL.h"
const SSDL_Image APPLE = SSDL_LoadImage("Goal_apple.jpg");
int main5(int argc, char** argv)
{
	SSDL_SetWindowTitle("Work in progress");
	SSDL_SetWindowSize(800, 600);
	SSDL_RenderImage(APPLE, SSDL_GetWindowWidth()/2,SSDL_GetWindowHeight()/2);
	
	SSDL_WaitKey();
	return 0;
}