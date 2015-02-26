#include <cstdio>
#include <iostream>

#include "bat.h"

Bat::Bat()
{

}

void Bat::render( SDL_Renderer* renderer, int x, int y)
{
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = 20;
    r.h = 90;

    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255);

    SDL_RenderFillRect( renderer, &r );
}

void Bat::onMouseMotion(SDL_MouseMotionEvent* mouse)
{
    std::cout << "X: " << mouse->x << " Y:" << mouse->y << std::endl;
}
