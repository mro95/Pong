#ifndef _Ball_H_
#define _Ball_H_

#include <SDL2/SDL.h>
#include "stage.h"
#include "main.h"

class Ball
{
    public:

        Ball( );

        void render( SDL_Renderer* renderer );

        SDL_Rect ball;
        Main main;
};

#endif
