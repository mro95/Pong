#include <cstdio>
#include <iostream>
#include <math.h>

#include "bat.h"
#include "rect.h"

#define MAX_SPEED 1200
#define BRAKE_SPEED 40

Bat::Bat(int x)
{
    targetY = 0;
    y = 0;
    dy = 0;
    this->x = x;
    width = 20;
    height = 90;
}

void Bat::control( int y )
{
    targetY = y;
}

void Bat::update( double dt )
{
    dy = BRAKE_SPEED * (targetY - y);
    if (dy > MAX_SPEED) dy = MAX_SPEED;
    if (dy < -MAX_SPEED) dy = -MAX_SPEED;
    y += dy * dt;      
}

void Bat::render( SDL_Renderer* renderer )
{

    //SDL_Rect r;
    double rx = x;
    double ry = y - (height / 2);
    double rw = width;
    double rh = height;

    Rect* rect = new Rect(rx,ry,rw,rh);
    SDL_Rect r = rect->getRect();

    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255);

    SDL_RenderFillRect( renderer, &r );
}
