#ifndef _Ball_H_
#define _Ball_H_

#include <SDL2/SDL.h>
#include "rect.h"

class Ball
{
    public:

        Ball( );

        void render( SDL_Renderer* renderer );
        void update( double dt );

        Rect ball;

        double x;
        double y;
        double dx;
        double dy;

};

#endif
