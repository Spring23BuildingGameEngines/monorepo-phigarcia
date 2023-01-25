// #ifndef _PlayerScore_H
// #define _PlayerScore_H

// #if defined(LINUX) || defined(MINGW)
// 	#include <SDL2/SDL.h>
//     // #include <SDL2/SDL_ttf.h> not working for linux path TODO 
// #else
// 	#include <SDL.h>
//     #include <SDL_ttf.h>
// #endif

// #include "Ball.hpp"

// class PlayerScore
// {
// public:
// 	PlayerScore(Vec2 position, SDL_Renderer* renderer, TTF_Font* font);

// 	~PlayerScore();

// 	void PlayerScoreDraw(SDL_Renderer* renderer);

// 	SDL_Renderer* renderer;
// 	TTF_Font* font;
// 	SDL_Surface* surface{};
// 	SDL_Texture* texture{};
// 	SDL_Rect textRect;
// };
// #endif