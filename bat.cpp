#include <cstdio>
#include <iostream>
#include <math.h>

#include "bat.h"
#include "rect.h"

#define MAX_SPEED 1200
#define BRAKE_SPEED 40

Bat::Bat(double x): bat(x, 0, 0, 0)
{
    targetY = 0;
    this->y = 0;
    dy = 0;
    this->x = x;
    width = 20;
    height = 90;
}

void Bat::control( int y )
{
    targetY = y - (height / 2);
}

//void Bat::update( double dt )
//{
//    dy = BRAKE_SPEED * (targetY - y);
//    if (dy > MAX_SPEED) dy = MAX_SPEED;
//    if (dy < -MAX_SPEED) dy = -MAX_SPEED;
//    y += dy * dt;
//}

void Bat::update( double dt )
{
    this->y = targetY;
}


void Bat::render( SDL_Renderer* renderer )
{
    bat.x = x;
    bat.y = y;
    bat.w = width;
    bat.h = height;
    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255);
    SDL_Rect r = bat.getRect();
    SDL_RenderFillRect( renderer, &r );
}

Rect* Bat::getRect()
{

    return &this->bat;
}
