#ifndef _NPC_H_
    #define _NPC_H_

#include <SDL2/SDL.h>
#include "bat.h"

class NPC
{
    public:
        NPC();
        void render( SDL_Renderer* renderer );
        void update( int dt );

};

#endif
