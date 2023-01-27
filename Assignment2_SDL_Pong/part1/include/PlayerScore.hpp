#ifndef _PlayerScore_H
#define _PlayerScore_H

#if defined(LINUX) || defined(MINGW)
	#include <SDL2/SDL.h>
    #include <SDL2/SDL_ttf.h>


#else
	#include <SDL.h>
    #include <SDL_ttf.h>
#endif

#include "Ball.hpp"

class PlayerScore
{
public:
	PlayerScore(Vec2 position, SDL_Renderer* renderer, TTF_Font* font);

	~PlayerScore();

	void DrawPlayerScore(SDL_Renderer* renderer);
	void SetScore(int score);

    int width, height;
	SDL_Renderer* renderer;
	TTF_Font* font;
	SDL_Surface* surface = TTF_RenderText_Solid(font, "0", {0xFF, 0xFF, 0xFF, 0xFF});
	SDL_Texture* texture;
	SDL_Rect textRect;
    Vec2 position;

};
#endif