#ifndef _stage_H_
    #define _stage_H_

#include <SDL2/SDL.h>
#include "bat.h"

class Stage
{
    public:
        Stage();
        void render( SDL_Renderer* renderer );

        void update( int dt );

        void onMouseMotion(SDL_MouseMotionEvent* mouse);

    private:
        Bat player;

};

#endif
