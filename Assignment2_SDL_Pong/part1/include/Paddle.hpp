#ifndef _Paddle_H
#define _Paddle_H

#if defined(LINUX) || defined(MINGW)
	#include <SDL2/SDL.h>
#else
	#include <SDL.h>
#endif

#include "Ball.hpp"

#define PADDLE_WIDTH 48
#define PADDLE_HEIGHT 128
#define PADDLE_SPEED 1.0f


class Paddle
{
public:
	Paddle(Vec2 position, Vec2 velocity, SDL_Renderer* renderer);
	void DrawPaddle(SDL_Renderer* renderer);
    void UpdatePaddle(float dt); 
	Vec2 position;
    Vec2 velocity;

	SDL_Rect paddleRect;
    SDL_Surface* image = SDL_LoadBMP("./media/paddle64.bmp");
    SDL_Texture* paddleTexture;
	
};

enum Buttons
{
	PaddleOneUp = 0,
	PaddleOneDown,
	PaddleTwoUp,
	PaddleTwoDown,
};



#endif