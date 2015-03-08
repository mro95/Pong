#include <iostream>
#include <unistd.h>
#include "circle.h"

Circle::Circle()
{

}

void Circle::createFilledCircle(int mx, int my, int r)
{
    Uint32* pixbuf;
    for (int y = -r; y <= r; y++) {
        pixbuf = (Uint32*)circle->pixels + circle->w * (my + y) + (mx - r);
        for (int x = -r; x <= r; x++) {
            if(x * x + y * y < r * r)
                *(pixbuf++) = 0xffffffff;
            else
                *(pixbuf++) = 0x00000000;
        }
    }
}

SDL_Surface* Circle::getCircle()
{
    return circle;
}

void Circle::setCircle(SDL_Surface* s)
{
    circle = s;
}
