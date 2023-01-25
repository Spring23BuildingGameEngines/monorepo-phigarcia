// Support Code written by Michael D. Shah
// Following Austin Morlan pong clone code
// Phi Garcia
// 1/27/23

#include <iostream>
#include <chrono>
#include "PongGame.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"

PongGame::PongGame() {

	// Initialize SDL components	
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "SDL could not be initialized: " <<
                  SDL_GetError();
    }else{
        std::cout << "SDL video system is ready to go\n";
    }

	window = SDL_CreateWindow("Pong!", 
	0, 
	0, 
	windowWidth, 
	windowHeight, 
	SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(window, -1, 0);
	windowSurface = SDL_GetWindowSurface(window);
	pongBackground = SDL_LoadBMP("./media/pong_bg600.bmp");
	pongTexture = SDL_CreateTextureFromSurface(renderer, pongBackground); 

	// if pong texture isnt available default to purple
	if (!pongBackground) {
			SDL_SetRenderDrawColor(renderer, 0x84, 0x42, 0xc6, 1);
	}

	rectangle.x = 0;
	rectangle.y = 0;
	rectangle.w = windowWidth;
	rectangle.h = windowHeight;


	ball = new Ball(Vec2((windowWidth / 2.0f) - (BALL_WIDTH / 2.0f),
  	(windowHeight / 2.0f) - (BALL_WIDTH / 2.0f)), 
	Vec2(BALL_SPEED, 0.0f),
	renderer);

	// Create the paddles
	paddleOne = new Paddle((Vec2(50.0f, (windowWidth / 2.0f) - (PADDLE_HEIGHT / 2.0f))), 
	Vec2(0.0f, 0.0f), 
	renderer);

	paddleTwo = new Paddle((Vec2(windowWidth - 50.0f, (windowHeight / 2.0f) - (PADDLE_HEIGHT / 2.0f))), 
	Vec2(0.0f, 0.0f), 
	renderer);

}

// Proper shutdown and destroy initialized objects
PongGame::~PongGame() {
		// Cleanup
	SDL_DestroyTexture(pongTexture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	//TTF_CloseFont(scoreFont)
	//TTF_Quit(); TOEDO
	SDL_Quit();
	// TODO how to deconstruct paddles, ~Paddle or ~PaddleOne?
}


void PongGame::Input() {	
	
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
					running = false;
			}
			
			else if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					running = false;
				}
				if (event.key.keysym.sym == SDLK_w)
				{
					buttons[Buttons::PaddleOneUp] = true;
				}
				else if (event.key.keysym.sym == SDLK_s)
				{
					buttons[Buttons::PaddleOneDown] = true;
				}
				else if (event.key.keysym.sym == SDLK_UP)
				{
					buttons[Buttons::PaddleTwoUp] = true;
				}
				else if (event.key.keysym.sym == SDLK_DOWN)
				{
					buttons[Buttons::PaddleTwoDown] = true;
				}
			}
			
			else if (event.type == SDL_KEYUP)
			{
				if (event.key.keysym.sym == SDLK_w)
				{
					buttons[Buttons::PaddleOneUp] = false;
				}
				else if (event.key.keysym.sym == SDLK_s)
				{
					buttons[Buttons::PaddleOneDown] = false;
				}
				else if (event.key.keysym.sym == SDLK_UP)
				{
					buttons[Buttons::PaddleTwoUp] = false;
				}
				else if (event.key.keysym.sym == SDLK_DOWN)
				{
					buttons[Buttons::PaddleTwoDown] = false;
				}
			}
		}
}

// Update OpenGL
void PongGame::Update() {
	// Update the paddle positions
	paddleOne->UpdatePaddle(dt);
	paddleTwo->UpdatePaddle(dt); // todo not moving
	ball->UpdateBall(dt);
	// std::cout << "updated paddles and balls" << std::endl;

	if (buttons[Buttons::PaddleOneUp])
	{
		paddleOne->velocity.y = -PADDLE_SPEED;
	}
	else if (buttons[Buttons::PaddleOneDown])
	{
		paddleOne->velocity.y = PADDLE_SPEED;
	}
	else
	{
		paddleOne->velocity.y = 0.0f;
	}

	if (buttons[Buttons::PaddleTwoUp])
	{
		paddleTwo->velocity.y = -PADDLE_SPEED;
	}
	else if (buttons[Buttons::PaddleTwoDown])
	{
		paddleTwo->velocity.y = PADDLE_SPEED;
	}
	else
	{
		paddleTwo->velocity.y = 0.0f;
	}

	// Check collisions
	if (contact = CheckPaddleCollision(ball, paddleOne), contact.type != CollisionType::None)
	{
		ball->CollideWithPaddle(&contact);
	}
	else if (contact = CheckPaddleCollision(ball, paddleTwo),
		contact.type != CollisionType::None)
	{
		ball->CollideWithPaddle(&contact);
	}
	else if (contact = CheckWallCollision(ball),
	contact.type != CollisionType::None)
	{
		ball->CollideWithWall(&contact);
	}


}


void PongGame::Render() { 
	RenderNet();
	ball->DrawBall(renderer); 
	paddleOne->DrawPaddle(renderer);
	paddleTwo->DrawPaddle(renderer);
}

// making this because the net stays up through the entire game
void PongGame::RenderNet() {
	net.x = windowWidth / 2 - 8;
	net.y = 25;
	net.w = 16;
	net.h = windowHeight - 50;  

	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderDrawRect(renderer, &net);
    SDL_RenderFillRect(renderer, &net);
} 

Contact PongGame::CheckWallCollision(Ball const *ball) {
	ballLeft = ball->position.x;
	ballRight = ball->position.x + BALL_WIDTH;
	ballTop = ball->position.y;
	ballBottom = ball->position.y + BALL_HEIGHT;

	if (ballLeft < 0.0f)
	{
		contact.type = CollisionType::Left;
		std::cout << "colliding with left" << std::endl;
	}
	else if (ballRight > WINDOW_WIDTH)
	{
		contact.type = CollisionType::Right;
	}
	else if (ballTop < 0.0f)
	{
		contact.type = CollisionType::Top;
		contact.penetration = -ballTop;
	}
	else if (ballBottom > WINDOW_HEIGHT)
	{
		contact.type = CollisionType::Bottom;
		contact.penetration = WINDOW_HEIGHT - ballBottom;
	}

	return contact;

}

Contact PongGame::CheckPaddleCollision(Ball const *ball, Paddle const *paddle)
{
	ballLeft = ball->position.x;
	ballRight = ball->position.x + BALL_WIDTH;
	ballTop = ball->position.y;
	ballBottom = ball->position.y + BALL_HEIGHT;

	paddleLeft = paddle->position.x;
	paddleRight = paddle->position.x + PADDLE_WIDTH;
	paddleTop = paddle->position.y;
	paddleBottom = paddle->position.y + PADDLE_HEIGHT;

	if (ballLeft >= paddleRight)
	{
		return contact;
	}

	if (ballRight <= paddleLeft)
	{
		return contact;
	}

	if (ballTop >= paddleBottom)
	{
		return contact;
	}

	if (ballBottom <= paddleTop)
	{
		return contact;
	}

	paddleRangeUpper = paddleBottom - (2.0f * PADDLE_HEIGHT / 3.0f);
	paddleRangeMiddle = paddleBottom - (PADDLE_HEIGHT / 3.0f);

	if (ball->velocity.x < 0)
	{
		// Left paddle
		contact.penetration = paddleRight - ballLeft;
	}
	else if (ball->velocity.x > 0)
	{
		// Right paddle
		contact.penetration = paddleLeft - ballRight;
	}

	if ((ballBottom > paddleTop) && (ballBottom < paddleRangeUpper))
	{
		contact.type = CollisionType::Top;
		std::cout << "colliding with top" << std::endl;
	}
	else if ((ballBottom > paddleRangeUpper)
	     && (ballBottom < paddleRangeMiddle))
	{
		contact.type = CollisionType::Middle;
	}
	else
	{
		contact.type = CollisionType::Bottom;
	}

	return contact;
}

void PongGame::Loop() {
	dt = 0.0f;


	while (running) {
		SDL_RenderClear(renderer);

		auto startTime = std::chrono::high_resolution_clock::now();
		
		Input();
		Update(); 


		SDL_RenderCopy(renderer, pongTexture, NULL, &rectangle);
		Render();

		SDL_RenderPresent(renderer);
		SDL_UpdateWindowSurface(window);

		// Calculate frame time
		auto stopTime = std::chrono::high_resolution_clock::now();
		dt = std::chrono::duration<float, std::chrono::milliseconds::period>(stopTime - startTime).count();
	}

	
}

int main(int argc, char* argv[])
{
	PongGame *pong = new PongGame();
		
	pong->Loop();

	delete pong; 

	return 0;
}