#include "ball.h"
#include "main.h"

Ball::Ball()
{

}

void Ball::render( SDL_Renderer* renderer )
{
    ball.x = ((main.windowWidth/2) - 10);
    ball.y = ((main.windowHeight/2) - 10);
    ball.w = 20;
    ball.h = 20;

    SDL_SetRenderDrawColor( renderer, 0, 255, 0, 255);

    SDL_RenderFillRect( renderer, &ball );
}
