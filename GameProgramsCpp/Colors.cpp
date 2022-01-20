#include "SSDL.h"
int main2(int argc, char** argv)
{
	SSDL_SetWindowTitle("Work in progress");
	const SSDL_Color RED = SSDL_CreateColor(225, 0, 0);
	const SSDL_Color BLUE = SSDL_CreateColor(0, 0, 225);
	const SSDL_Color GREEN = SSDL_CreateColor(0, 225, 0);
	const SSDL_Color GRAY = SSDL_CreateColor(100, 100, 100); 
	SSDL_SetRenderEraseColor(GRAY);
	SSDL_RenderClear();
	SSDL_SetRenderDrawColor(BLUE);
	SSDL_RenderFillRect(100, 100, 100, 100);
	SSDL_SetRenderDrawColor(GREEN);
	SSDL_RenderFillCircle(200, 200, 50);
	SSDL_WaitKey();
	SSDL_RenderClear(RED);
	SSDL_WaitKey();
	return 0; 
}