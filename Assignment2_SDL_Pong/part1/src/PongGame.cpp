// Support Code written by Michael D. Shah
// Following Austin Morlan pong clone code
// Phi Garcia
// 1/27/23

#include <iostream>
#include <chrono>
#include "PongGame.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"
#include <math.h>

PongGame::PongGame()
{

	// Initialize SDL components
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL could not be initialized: " << SDL_GetError();
	}
	else
	{
		std::cout << "SDL video system is ready to go\n";
	}

 	if(TTF_Init() == -1)
	{
        std::cout << "Could not initailize SDL2_ttf, error: " << TTF_GetError() << std::endl;
    }
	else 
	{
        std::cout << "SDL2_ttf system ready to go!" << std::endl;
	}
    // Confirm that it was loaded
    if(scoreFont == nullptr){
        std::cout << "Could not load font" <<  TTF_GetError() << std::endl;
        exit(1);
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
	if (!pongBackground)
	{
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

	playerOneScoreText = new PlayerScore(Vec2(windowWidth / 4, 20), renderer, scoreFont);
	playerTwoScoreText = new PlayerScore(Vec2(3 * windowWidth / 4, 20), renderer, scoreFont);
}

// Proper shutdown and destroy initialized objects
PongGame::~PongGame()
{
	// Cleanup
	SDL_DestroyTexture(pongTexture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_CloseFont(scoreFont);
	TTF_Quit(); 
	SDL_Quit();
	// TODO how to deconstruct paddles, ~Paddle or ~PaddleOne?
}

void PongGame::Input()
{

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			running = false;
		}

		else if (event.type == SDL_KEYDOWN)
		{
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
void PongGame::Update()
{
	Contact contact = { .type = CollisionType::None, .penetration = 0.0f };
	
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

		if (contact.type == CollisionType::Left)
			{
				++playerTwoScore;
				playerTwoScoreText->SetScore(playerTwoScore);
			}
			else if (contact.type == CollisionType::Right)
			{
				++playerOneScore;
				playerOneScoreText->SetScore(playerOneScore);
			}
	}
}

void PongGame::Render()
{
	RenderNet();

	paddleOne->DrawPaddle(renderer);
	paddleTwo->DrawPaddle(renderer);
	ball->DrawBall(renderer);

	playerOneScoreText->DrawPlayerScore(renderer);
	playerTwoScoreText->DrawPlayerScore(renderer);

}

// making this because the net stays up through the entire game
void PongGame::RenderNet()
{
	net.x = windowWidth / 2;
	net.y = 25;
	net.w = 16;
	net.h = windowHeight - 50;

	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderDrawRect(renderer, &net);
	SDL_RenderFillRect(renderer, &net);
}

Contact PongGame::CheckWallCollision(Ball const *ball)
{
	Contact contact{};
	float ballLeft = ball->position.x;
	float ballRight = ball->position.x + BALL_WIDTH;
	float ballTop = ball->position.y;
	float ballBottom = ball->position.y + BALL_HEIGHT;


	if (ballLeft < 0.0f)
	{
		contact.type = CollisionType::Left;
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
	Contact contact{};
	float ballLeft = ball->position.x;
	float ballRight = ball->position.x + BALL_WIDTH;
	float ballTop = ball->position.y;
	float ballBottom = ball->position.y + BALL_HEIGHT;

	float paddleLeft = paddle->position.x;
	float paddleRight = paddle->position.x + PADDLE_WIDTH;
	float paddleTop = paddle->position.y;
	float paddleBottom = paddle->position.y + PADDLE_HEIGHT;

	if (ballLeft <= paddleRight)
	{	 return contact;

		std::cout << "hit left paddle" << std::endl;
		// return {.type = CollisionType::Right, .penetration = paddleRight - ballLeft};	
	} // todo fix all these

	if (ballRight >= paddleLeft)
	{	return contact;

		std::cout << "hit right paddle" << std::endl;
		// return {.type = CollisionType::Left, .penetration = ballRight - paddleLeft};	
	}

	if (ballTop <= paddleBottom)
	{	return contact;
		std::cout << "hit bottom" << std::endl;
		// return {.type = CollisionType::Bottom, .penetration = paddleBottom - ballTop};
	}

	if (ballBottom >= paddleTop)
	{
		return contact;
		// return {.type = CollisionType::Top, .penetration = ballBottom - paddleTop};	
	}
		
		std::cout << "No collision" << std::endl;

	paddleRangeUpper = paddleBottom - (2.0f * PADDLE_HEIGHT / 3.0f);
	paddleRangeMiddle = paddleBottom - (PADDLE_HEIGHT / 3.0f);

	if (ball->velocity.x < 0)
	{
		// Left paddle		
		// return {.type = CollisionType::None, .penetration = paddleRight - ballLeft};

		contact.penetration = paddleRight - ballLeft;
	}
	else if (ball->velocity.x > 0)
	{
		// Right paddle
		// return {.type = CollisionType::None, .penetration = paddleLeft - ballRight};

		contact.penetration = paddleLeft - ballRight;
	}

	if ((ballBottom > paddleTop) && (ballBottom < paddleRangeUpper))
	{
				contact.type = CollisionType::Top;
		// return {.type = CollisionType::Top, .penetration = 0.0f};
		std::cout << "colliding with top paddle" << std::endl;
	}
	else if ((ballBottom > paddleRangeUpper) && (ballBottom < paddleRangeMiddle))
	{
		contact.type = CollisionType::Middle;
		std::cout << "colliding with middle paddle" << std::endl;

		// return {.type = CollisionType::Middle, .penetration = 0.0f};
	}
	else
	{
		contact.type = CollisionType::Bottom;
		std::cout << "colliding with bottom paddle" << std::endl;
		// return {.type = CollisionType::Bottom, .penetration = 0.0f};
	}
	return contact;
}

void PongGame::Loop()
{
	dt = 0.0f;
	Uint64 prevFrameStart;

	while (running)
	{
		Uint64 start = SDL_GetPerformanceCounter();
		auto startTime = std::chrono::high_resolution_clock::now();
		SDL_RenderClear(renderer);


		Input();
		Update();

		SDL_RenderCopy(renderer, pongTexture, NULL, &rectangle);
		Render();
	
		SDL_RenderPresent(renderer);
		// SDL_UpdateWindowSurface(window);

		Uint64 end = SDL_GetPerformanceCounter();
		float elapsed = ((float)end - start) / (float)SDL_GetPerformanceFrequency() / 1000.0f;
		
		//std::cout << "Current FPS: " << std::to_string(1.0f / elapsed) << std::endl;
		std::cout << "ball position: " << ball->position.x << std::endl;

		std::cout << "paddle1 position: " << paddleOne->position.x << std::endl;

		std::cout << "paddle2 position: " << paddleTwo->position.x << std::endl;

		SDL_Delay(floor(16.666f - elapsed));

		// Calculate frame time
		auto stopTime = std::chrono::high_resolution_clock::now();
		dt = std::chrono::duration<float, std::chrono::milliseconds::period>(stopTime - startTime).count();
		prevFrameStart = start;
	}
}

int main(int argc, char *argv[])
{
	PongGame *pong = new PongGame();

	pong->Loop();

	delete pong; // todo can we use delete

	return 0;
}