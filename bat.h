#ifndef _bat_H_
    #define _bat_H_

#include <SDL2/SDL.h>
#include "rect.h"

class Bat
{
    public:
        Bat(double x);
        void render( SDL_Renderer* renderer);
        void update( double dt );
        void control( int y );
        Rect* getRect();


        double targetY;
        double y;
        double dy;
        double x;
        double width;
        double height;

    private:

        Rect bat;

};

#endif
