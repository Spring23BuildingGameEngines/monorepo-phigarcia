
#include <iostream>
#include "Ball.hpp"
#include "PongGame.hpp"

Ball::Ball(Vec2 position, Vec2 velocity, SDL_Renderer *renderer): position(position), velocity(velocity) {
	    ballRect.x = static_cast<int>(position.x);
	    ballRect.y = static_cast<int>(position.y);
	    ballRect.w = BALL_WIDTH;
	    ballRect.h = BALL_HEIGHT;

	ballTexture = SDL_CreateTextureFromSurface(renderer, image);

    };
    
void Ball::UpdateBall(float dt)
{
	position += velocity * dt;
}


void Ball::DrawBall(SDL_Renderer *renderer) {
	ballRect.x = static_cast<int>(position.x);
	ballRect.y = static_cast<int>(position.y);
    
    SDL_RenderCopy(renderer, ballTexture, nullptr, &ballRect);  
}

void Ball::CollideWithPaddle(Contact const *contact)
	{
		position.x += contact->penetration;
		velocity.x = -velocity.x;

		if (contact->type == CollisionType::Top)
		{
			velocity.y = -.75f * BALL_SPEED;
		}
		else if (contact->type == CollisionType::Bottom)
		{
			velocity.y = 0.75f * BALL_SPEED;
		}

       	std::cout << "Collide with paddle velocity" << velocity.x << ", " << velocity.y << std::endl;
	}


void Ball::CollideWithWall(Contact const *contact)
	{
		if ((contact->type == CollisionType::Top)
		    || (contact->type == CollisionType::Bottom))
		{
			position.y += contact->penetration;
			velocity.y = -velocity.y;
		}
		else if (contact->type == CollisionType::Left)
		{
			position.x = WINDOW_WIDTH / 2.0f;
			position.y = WINDOW_HEIGHT / 2.0f;
			velocity.x = BALL_SPEED;
			velocity.y = 0.75f * BALL_SPEED;
		}
		else if (contact->type == CollisionType::Right)
		{
			position.x = WINDOW_WIDTH / 2.0f;
			position.y = WINDOW_HEIGHT / 2.0f;
			velocity.x = -BALL_SPEED;
			velocity.y = 0.75f * BALL_SPEED;
		}
	}

// SDL_Rect Ball::GetBallRect() 
// {
//     return this.
// }