#ifndef _PongGame_H
#define _PongGame_H

#if defined(LINUX) || defined(MINGW)
	#include <SDL2/SDL.h>
    //#include <SDL2/SDL_ttf.h> TODO
#else
	#include <SDL.h>
   // #include <SDL_ttf.h>
#endif

#include "Ball.hpp"
#include "Paddle.hpp"

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 720

class PongGame{
public:

    // Constructor
    PongGame();
    // Desctructor
    ~PongGame();
    // takes input
    void Input();
    // Per frame update
    void Update();
    // Renders shapes to the screen
    void Render();
    // render the net once and keep it there
    void RenderNet();
    Contact CheckWallCollision(Ball const *ball);

    Contact CheckPaddleCollision(Ball const *ball, Paddle const *paddle);
    // loop that runs forever
    void Loop();

    // The window we'll be rendering to
    SDL_Window* window ;
    SDL_Event event;

    // SDL Renderer
    SDL_Renderer *renderer = NULL;
    SDL_Surface *windowSurface;
	SDL_Surface *pongBackground;
	SDL_Texture *pongTexture; 
    SDL_Rect rectangle;
    SDL_Rect net; // making a rectangle for the net
        // Screen dimension constants
    int windowHeight = 600;
    int windowWidth = 720;
    //TTF_Font* scoreFont = TTF_OpenFont("MinecraftRegular-Bmg3.ttf", 40);
    Ball *ball; 
    Paddle *paddleOne;
    Paddle *paddleTwo;
    float dt;
	bool buttons[4] = {};
    

    float ballLeft;
	float ballRight;
	float ballTop;
	float ballBottom;

	float paddleLeft;
	float paddleRight;
	float paddleTop;
	float paddleBottom;

    Contact contact; 
    float paddleRangeUpper;
	float paddleRangeMiddle;

private:
    bool running = true;

};

#endif
