#ifndef RECT_H
#define RECT_H

#include <SDL2/SDL.h>

class Rect
{
    public:
        double x;
        double y;
        double w;
        double h;

        SDL_Rect r;

        Rect( double x, double y, double w, double h);
        SDL_Rect getRect();
        bool contains (double x, double y);
        bool collision(Rect* other);
};

#endif // RECT_H
