#include "AIE.h"
#include <iostream>

int main( int argc, char* argv[] )
{	
	//constant vars
	static int SCREEN_MAX_X = 1200, SCREEN_MAX_Y = 700;
	static float SPEED = 0.5f;

	Initialise(SCREEN_MAX_X, SCREEN_MAX_Y, false, "My Awesome Game");
    
    SetBackgroundColour(SColour(0, 0, 0, 255));

	int img1 = CreateSprite("./images/invaders/invaders_1_00.png", 64, 64, true);
	int img2 = CreateSprite("./images/invaders/invaders_1_01.png", 64, 64, true);
	int myTextureHandle = img1;

    float xPos = 100;
    float yPos = 100;

	float time = 0;
	float interval = 0.8f;

	//direction vars
	bool movingRight = true;
	bool movingUp = true;

	//key vars	
	bool xKeyDown = false;
	bool yKeyDown = false;

    //Game Loop
    do
	{
		time += GetDeltaTime();
		if (time > interval) {
			time -= interval;
			if (myTextureHandle == img1) {
				myTextureHandle = img2;
			} else {
				myTextureHandle = img1;
			}
		}

		//movement code
		if (movingRight) {
			xPos += SPEED;
			if (xPos > SCREEN_MAX_X) {
				movingRight = !movingRight;
				xPos = SCREEN_MAX_X;
			}
		}
		else 
		{
			xPos -= SPEED;
			if (xPos < 0) {
				movingRight = !movingRight;
				xPos = 0;
			}
		}

		if (movingUp) {
			yPos += SPEED;
			if (yPos > SCREEN_MAX_Y) {
				movingUp = !movingUp;
			}
		}
		else
		{
			yPos -= SPEED;
			if (yPos < 0) {
				movingUp = !movingUp;
			}
		}

		//input Code
		if (IsKeyDown(88) && !xKeyDown) {
			movingRight = !movingRight;
			xKeyDown = true;
		}
		else if (!IsKeyDown(88)) {
			xKeyDown = false;
		}


		if (IsKeyDown(89) && !yKeyDown) {
			movingUp = !movingUp;
			yKeyDown = true;
		}
		else if (!IsKeyDown(89)) {
			yKeyDown = false;
		}

		//draw/finalize move
        MoveSprite(myTextureHandle, xPos, yPos);
		DrawSprite(myTextureHandle);

        ClearScreen();

    } while(!FrameworkUpdate());

    Shutdown();

    return 0;
}
