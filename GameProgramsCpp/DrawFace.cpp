#include "SSDL.h" 

int main1(int argc, char** argv)
{
	sout << "Hello, world!  (Press any key to quit.)\n";
	SSDL_SetWindowSize(800, 600);
	SSDL_RenderDrawLine(220, 100, 285, 45);
	SSDL_RenderDrawLine(285, 45, 380, 140);
	SSDL_RenderDrawLine(520, 160, 570, 40);
	SSDL_RenderDrawLine(570, 40, 630, 95);
	SSDL_RenderDrawLine(290, 360, 380, 420);
	SSDL_RenderDrawLine(380, 420, 500, 410);
	SSDL_RenderDrawCircle(440, 290, 210);
	SSDL_RenderDrawCircle(330, 265, 50);
	SSDL_RenderDrawCircle(475, 280, 50);



	SSDL_WaitKey();

	return 0;
}