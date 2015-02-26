#include <cstdio>
#include <iostream>

#include "main.h"
#include "stage.h"
#include "ball.h"
#include "bat.h"

Stage::Stage()
{

}

void Stage::render( SDL_Renderer* renderer )
{
     SDL_SetRenderDrawColor( renderer, 0, 175, 255, 255 );

     player.render( renderer, 20, 20);

     Bat npc;
     npc.render( renderer, 760, 490);

     Ball ball;
     ball.render( renderer );
}

void Stage::update( int dt )
{

}

void Stage::onMouseMotion(SDL_MouseMotionEvent* mouse)
{
    player.onMouseMotion(mouse);
}
