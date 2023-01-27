#include "PlayerScore.hpp"
#include <iostream>

PlayerScore::PlayerScore(Vec2 position, SDL_Renderer* renderer, TTF_Font* font): renderer(renderer), font(font)
	{
		textRect.x = static_cast<int>(position.x);
		textRect.y = static_cast<int>(position.y);
		textRect.w = width;
		textRect.h = height;

        texture = SDL_CreateTextureFromSurface(renderer, surface);

	}

PlayerScore::~PlayerScore()
{
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}
void PlayerScore::DrawPlayerScore(SDL_Renderer* renderer)
{
    // textRect.x = 40;
	// textRect.y = 40;

	// SDL_RenderCopy(renderer, texture, nullptr, &textRect);
    // std::cout << "Score being drawn" << std::endl;

    // textRect.w = 10;
    // textRect.y = 10;

    // SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
	// SDL_RenderDrawRect(renderer, &textRect);
	// SDL_RenderFillRect(renderer, &textRect);
}

void PlayerScore::SetScore(int score)
{
    // SDL_FreeSurface(surface);
	// SDL_DestroyTexture(texture);

	// surface = TTF_RenderText_Solid(font, std::to_string(score).c_str(), {0xFF, 0xFF, 0xFF, 0xFF});
	// texture = SDL_CreateTextureFromSurface(renderer, surface);

	// textRect.w = width;
	// textRect.h = height;
}
