#include "ball.h"
#include "main.h"

Ball::Ball(): ball(x,y,20,20)
{
    x = ((800/2) - (20 / 2));
    y = ((600/2) - (20 / 2));
    dx = 1000;
    dy = 1000;
}

void Ball::render( SDL_Renderer* renderer )
{
    ball.w = 20;
    ball.h = 20;
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
