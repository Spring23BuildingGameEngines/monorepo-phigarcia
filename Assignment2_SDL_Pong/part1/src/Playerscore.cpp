// #include "PlayerScore.hpp"
// #include <iostream>

// PlayerScore::PlayerScore(Vec2 position, SDL_Renderer* renderer, TTF_Font* font): renderer(renderer), font(font)
// 	{
// 		surface = TTF_RenderText_Solid(font, "0", {0xFF, 0xFF, 0xFF, 0xFF});
// 		texture = SDL_CreateTextureFromSurface(renderer, surface);

// 		int width, height;
// 		SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

// 		textRect.x = static_cast<int>(position.x);
// 		textRect.y = static_cast<int>(position.y);
// 		textRect.w = width;
// 		textRect.h = height;
// 	}

// PlayerScore::~PlayerScore()
// {
// 	SDL_FreeSurface(surface);
// 	SDL_DestroyTexture(texture);
// }
// void PlayerScore::PlayerScoreDraw(SDL_Renderer* renderer)
// {
// 	SDL_RenderCopy(renderer, texture, nullptr, &rect);
// }