#include "ball.h"
#include "main.h"

Ball::Ball(): ball(x,y,20,20)
{
    x = ((800/2) - (20 / 2));
    y = ((600/2) - (20 / 2));
    w = 20;
    h = 20;

    dx = 500;
    dy = 500;

    a = false;
    b = false;
}

void Ball::render( SDL_Renderer* renderer )
{
    ball.w = w;
    ball.h = h;
    ball.x = x;
    ball.y = y;

    SDL_SetRenderDrawColor( renderer, 0, 255, 0, 255);
    SDL_Rect r = ball.getRect();
    SDL_RenderFillRect( renderer, &r );
}

void Ball::update( double dt )
{
    x += dx * dt;
    y += dy * dt;
}

bool Ball::collision(Rect* other)
{
    return ball.collision(other);
}
