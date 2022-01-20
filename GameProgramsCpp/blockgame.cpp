#include "SSDL.h"
#include <iostream>
#include <time.h>
int main(int argc, char** argv)
{
	srand(time(NULL));
	int x = 10;
	int y = -5;
	SSDL_SetWindowTitle("Work in progress");
	SSDL_SetWindowSize(700, 500);
	/*SSDL_RenderFillRect(x, y, 100, 100);
	SSDL_WaitKey();
	x += 100;
	y += 100;
	SSDL_RenderFillRect(x, y, 100, 100);
	SSDL_WaitKey();*/
	SSDL_SetFramesPerSecond(20);
	int randy[8]; 
	int randx[8];
	int randspeed[8];
	int randy2[8];
	int randx2[8];
	int randspeed2[8];
	bool gameover = false;
	bool stopwhile = false;
	const SSDL_Color RED = SSDL_CreateColor(225, 0, 0);
	const SSDL_Color BLUE = SSDL_CreateColor(0, 0, 225);
	const SSDL_Font MYFONT = SSDL_OpenSystemFont("ITCBLKAD.TTF", 50);
	time_t timer;

	for (int i = 0; i < 8;i++)
	{
		randspeed[i] =4+ rand() % 6;
		randy[i] = rand() % 410;
		randx[i] = 0 + rand() % 250;
		randspeed2[i] =4+ rand() % 6;
		randy2[i] = rand() % 410;
		randx2[i] = 800- rand() % 250;

	}
	SSDL_Sprite PLANE = SSDL_LoadImage("green-plane.png");	
	int planey = SSDL_GetWindowHeight() - 80;
	int planex = (SSDL_GetWindowWidth() / 2) - 50;
	SSDL_SetSpriteLocation(PLANE, planex, planey);
	SSDL_SetSpriteSize(PLANE, 70, 70);

	SSDL_Sprite Explosion = SSDL_LoadImage("Explosion.png");
	SSDL_SetSpriteLocation(Explosion, 100, 10);



	while (SSDL_IsNextFrame()&& !stopwhile)
	{
		srand(time(NULL));
		SSDL_DefaultEventHandler();
		SSDL_RenderClear();
		SSDL_RenderSprite(PLANE);
		if (!gameover)
		{
			if (SSDL_IsKeyPressed(SDLK_UP))
				planey -= 6;
			if (SSDL_IsKeyPressed(SDLK_DOWN))
				planey += 6;
			if (SSDL_IsKeyPressed(SDLK_RIGHT))
				planex += 6;
			if (SSDL_IsKeyPressed(SDLK_LEFT))
				planex -= 6;
		}
				
		SSDL_SetSpriteLocation(PLANE, planex, planey);

		for (int i = 0; i < 6;i++)
		{
			SSDL_Sprite BOMB = SSDL_LoadImage("Bomb.png");
			SSDL_SetSpriteLocation(BOMB, randx[i], y + randy[i]);
			SSDL_RenderSprite(BOMB);
			randx[i] += randspeed[i];

			SSDL_Sprite BOMB2 = SSDL_LoadImage("Bomb.png");
			SSDL_SetSpriteLocation(BOMB2, randx2[i], y + randy2[i]);
			SSDL_RenderSprite(BOMB2);
			randx2[i] -= randspeed2[i];

			if (randx[i] > 800)
			{
				randx[i] = 0;
				randspeed[i] = 4 + rand() % 6;
			}
			if (randx2[i] < 0)
			{
				randx2[i] = 800;
				randspeed2[i] = 4 + rand() % 6;
			}
			if ((SSDL_SpriteHasIntersection(BOMB, PLANE)|| SSDL_SpriteHasIntersection(BOMB2, PLANE))&&!gameover)
			{
				gameover = true;
				timer = time(NULL);
				SSDL_SetSpriteLocation(Explosion, planex + 5, planey + 4);			
			
			}
			
		}
		if(gameover)
		{ 
			SSDL_RenderSprite(Explosion);
			if (difftime(time(NULL),timer)==2)
			{
				SSDL_RenderClear();
				stopwhile = true;
			}

		}
		
	}
	SSDL_SetFont(MYFONT);
	SSDL_SetRenderDrawColor(RED);
	SSDL_RenderTextCentered("Game Over", 350, 60);

	
	SSDL_WaitKey();
	return 0;
}