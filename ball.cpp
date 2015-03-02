#include "ball.h"
#include "main.h"
#include <math.h>

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

    //SDL_Surface* surface = SDL_CreateRGBSurface(0, 50,50,32,255,0,0,255);
    fill_circle(renderer, 500,500,100);
    fill_circle(renderer, 200,200,100);
    fill_circle(renderer, 240,300,100);
    fill_circle(renderer, 360,600,100);
    fill_circle(renderer, 480,300,100);
    fill_circle(renderer, 340,400,100);
    fill_circle(renderer, 360,300,100);
    fill_circle(renderer, 380,100,100);
//    fill_circle(renderer, 440,300,100);
//    fill_circle(renderer, 460,500,100);
//    fill_circle(renderer, 480,200,100);

    //DrawCircle(surface, 100);
    //SDL_CreateTextureFromSurface(renderer, surface);
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

void Ball::respawn()
{
    x = ((800/2) - (20 / 2));
    y = ((600/2) - (20 / 2));

    int rand1 = rand() % 10;
    int rand2 = rand() % 10;

    if(rand1 > 5)
        dx = 500;
    else
        dx = -500;

    if(rand2 > 5)
        dy = 500;
    else
        dy = -500;
}

void Ball::fill_circle(SDL_Renderer* renderer, int x, int y, int r)
{
    int hx = x/2;
    int mhx = -(x/2);
    int hy = y/2;
    int mhy = -(y/2);
    for(double ix=mhx; ix < x;ix++)
    {
        for(double iy=mhy; iy < y;iy++)
        {
            //a = iy / precision * TAU;
            //SDL_RenderDrawPoint( renderer, x + cos(a) * r, y + sin(a) * r);
            double cx = ix;
            double ic = pow(ix, 2) + pow(iy, 2);
            if(ic - cx < r)
            {
                SDL_RenderDrawPoint( renderer, hx+ix,hy+iy);
            }
        }
    }
}
