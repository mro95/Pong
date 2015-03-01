#include <cstdio>
#include <iostream>
#include <unistd.h>

#include "main.h"
#include "stage.h"
#include "ball.h"
#include "bat.h"

Stage::Stage(): player(20),npc(800-40)
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

    //Wall Down
    if((ball.y + ball.h) >= Main::windowHeight)
    {
        ball.dy = -(abs(ball.dy));
    }

    //Wall Right
    if((ball.x + ball.w) >= Main::windowWidth)
    {
        ball.dx = -(abs(ball.dx));
    }

    //Wall Up
    if((ball.y + ball.h) <= ball.h)
    {
        ball.dy = abs(ball.dy);
    }

    //Wall Right
    if((ball.x + ball.w) <= ball.w)
    {
        ball.dx = abs(ball.dx);
    }


    Rect* npc = this->npc.getRect();
    if(ball.collision(npc))
    {
        ball.dx = -(abs(ball.dx)+10);
        ball.dy = ball.dy+5;
    }

    Rect* player = this->player.getRect();
    if(ball.collision(player))
    {
        ball.dx = (abs(ball.dx)+10  );
        ball.dx = ball.dx+5;
    }

}

void Stage::onMouseMotion(SDL_MouseMotionEvent* mouse)
{
    player.control( mouse->y );
}
