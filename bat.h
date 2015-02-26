#ifndef _bat_H_
    #define _bat_H_

#include <SDL2/SDL.h>

class Bat
{
    public:
        Bat( );
        void render( SDL_Renderer* renderer, int x, int y);
        void onMouseMotion(SDL_MouseMotionEvent* mouse);
};

#endif
