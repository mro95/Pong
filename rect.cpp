#include <math.h>
#include <SDL2/SDL.h>
#include <iostream>

#include "rect.h"

Rect::Rect(double x, double y, double w, double h)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

SDL_Rect Rect::getRect()
{
    r.x = x;
    r.y = y;
    r.w = w;
    r.h = h;
    return this->r;
}

bool Rect::contains(double x, double y) {
    // (x,y) is het punt, rect is de thisngle (met properties x,y,w,h)
    return (x < this->x + this->w)
        && (x > this->x)
        && (y < this->y + this->h)
        && (y > this->y);
}

bool Rect::collision(Rect* other) {
    // this en other zijn thisngles (met properties x,y,w,h)
    return fmax(this->x, other->x) <= fmin(this->x + this->w, other->x + other->w)
        && fmax(this->y, other->y) <= fmin(this->y + this->h, other->y + other->h);
}
