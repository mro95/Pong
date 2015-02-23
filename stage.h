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

        void onMouseMosion( SDL_MouseMotionEvent* ev );

};

#endif
