#include "Paddle.hpp"
#include "PongGame.hpp"
#include <iostream>	

Paddle::Paddle(Vec2 position, Vec2 velocity,  SDL_Renderer *renderer): position(position), velocity(velocity) {
	paddleRect.x = static_cast<int>(position.x);
	paddleRect.y = static_cast<int>(position.y);
	paddleRect.w = PADDLE_WIDTH;
	paddleRect.h = PADDLE_HEIGHT;

    paddleTexture = SDL_CreateTextureFromSurface(renderer, image);
}

void Paddle::DrawPaddle(SDL_Renderer* renderer)
{
	paddleRect.y = static_cast<int>(position.y);

    SDL_RenderCopy(renderer, paddleTexture, nullptr, &paddleRect);  
	// std::cout << "paddle y" << paddleRect.y << std::endl;
}

void Paddle::UpdatePaddle(float dt)
{
	//position.y = velocity.y * dt; 
		position += velocity * dt;

		if (position.y < 0)
		{
			// Restrict to top of the screen
			position.y = 0;
		}
		else if (position.y > (WINDOW_HEIGHT - PADDLE_HEIGHT))
		{
			// Restrict to bottom of the screen
			position.y = WINDOW_HEIGHT - PADDLE_HEIGHT;
		}
		
}


