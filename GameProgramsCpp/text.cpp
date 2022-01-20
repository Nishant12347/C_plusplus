#include "SSDL.h"
const SSDL_Color RED = SSDL_CreateColor(225, 0, 0);
const SSDL_Color BLUE = SSDL_CreateColor(0, 0, 225);
const SSDL_Color GREEN = SSDL_CreateColor(0, 225, 0);
const SSDL_Color GRAY = SSDL_CreateColor(100, 100, 100);
const SSDL_Font MYFONT = SSDL_OpenSystemFont("ITCBLKAD.TTF", 50);
int main4(int argc, char** argv)
{
	SSDL_SetWindowTitle("Work in progress");
	SSDL_SetWindowSize(800, 600);
	SSDL_SetFont(MYFONT);
	SSDL_SetRenderDrawColor(RED);
	SSDL_RenderTextCentered("hello world", 400, 30);
	SSDL_SetCursor(200, 200);
	SSDL_SetRenderDrawColor(BLUE);
	sout << "hello world";
	SSDL_WaitKey();
	return 0;

}