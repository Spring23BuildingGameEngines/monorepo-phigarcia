#ifndef _Ball_H
#define _Ball_H

#if defined(LINUX) || defined(MINGW)
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

#define BALL_WIDTH 16
#define BALL_HEIGHT 16
#define BALL_SPEED 0.75f

enum class CollisionType
{
	None,
	Top,
	Middle,
	Bottom,
	Left,
	Right

};

struct Contact
{
	CollisionType type;
	float penetration;
};

// the position and momentum vector for the ball
class Vec2
{
public:
	Vec2() : x(0.0f), y(0.0f) {}

	Vec2(float x, float y) : x(x), y(y) {}

	Vec2 operator+(Vec2 const &rhs) { return Vec2(x + rhs.x, y + rhs.y); }

	Vec2 &operator+=(Vec2 const &rhs)
	{
		x += rhs.x;
		y += rhs.y;

		return *this;
	}

	Vec2 operator*(float rhs)
	{
		return Vec2(x * rhs, y * rhs);
	}

	float x, y;
};

// ball itself
class Ball
{
public:
	Ball(Vec2 position, Vec2 velocity, SDL_Renderer *renderer);

	SDL_Rect ballRect;

	// updates the ball
	void UpdateBall(float dt);
	// renders the ball
	void DrawBall(SDL_Renderer *renderer);
	// checks for colliding with paddle
	void CollideWithPaddle(Contact const *contact);
	// checks for colliding with wall
	void CollideWithWall(Contact const *contact);

	Vec2 position;
	Vec2 velocity;

	SDL_Surface *image = SDL_LoadBMP("./media/ball.bmp");
	SDL_Texture *ballTexture;
};

#endif
