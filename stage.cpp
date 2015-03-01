#include <cstdio>
#include <iostream>

#include "main.h"
#include "stage.h"
#include "ball.h"
#include "bat.h"

Stage::Stage():player(20), npc(800-40)
{
}

void Stage::render( SDL_Renderer* renderer )
{
     SDL_SetRenderDrawColor( renderer, 0, 175, 255, 255 );

     player.render( renderer );

     npc.render( renderer );

     ball.render( renderer );
}

void Stage::update( double dt )
{
    player.update( dt );

    npc.control( ball.y );
    npc.update( dt );

    ball.update( dt );
}

void Stage::onMouseMotion(SDL_MouseMotionEvent* mouse)
{
    player.control( mouse->y );
}
