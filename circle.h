#ifndef CIRCLE_H
#define CIRCLE_H

#include <SDL2/SDL.h>
#include <math.h>

class Circle
{
    public:
        Circle();
        void createFilledCircle(int mx, int my, int r);
        SDL_Surface* getCircle();
        void setCircle(SDL_Surface* s);

    private:
        SDL_Surface* circle;
};

#endif // CIRCLE_H
