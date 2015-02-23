#ifndef _Bat_H_
#define _Bat_H_

#include <SDL2/SDL.h>
#include "stage.h"

class Bat
{
    public:
        Bat( );
        void render( SDL_Renderer* renderer, int x, int y);
};

#endif
