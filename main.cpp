#include <iostream>
#include "main.h"

Main::Main( )
{
    running = true;

    window = NULL;
    renderer = NULL;
}

int Main::execute( )
{
    if( !initialize() )
        return -1;

    SDL_Event sdlEvent;

    Uint32 lastFrame = SDL_GetTicks();
    Uint32 now;
    int dt;

    while ( running )
    {
        while ( SDL_PollEvent( &sdlEvent ))
            handleEvent( &sdlEvent );

        now = SDL_GetTicks();
        dt = now - lastFrame;
        lastFrame = now;

        update( dt );
        render( );

        SDL_Delay( 1 );
    }

    return 0;
}

bool Main::initialize( )
{
    if ( SDL_Init( SDL_INIT_EVERYTHING ) != 0 )
        return false;

    window = SDL_CreateWindow(
                "Pong",
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                windowWidth, windowHeight,
                0 );

    if ( window == NULL )
        return false;

    renderer = SDL_CreateRenderer( window, -1, 0 );

    if ( renderer == NULL )
        return false;

    return true;
}

void Main::render( )
{
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );

    SDL_RenderClear( renderer );

    stage.render( renderer );

    SDL_RenderPresent( renderer );
}

void Main::update( int dt )
{
    stage.update( dt );
}

void Main::handleEvent( SDL_Event* event )
{
    if ( event->type == SDL_QUIT )
        running = false;

    if ( event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_ESCAPE )
    {
        running = false;
        return;
    }

    if( event->type == SDL_MOUSEMOTION)
    {
        stage.onMouseMotion(&event->motion);
    }

}

int main(int argc, char* args[])
{
    Main game;
    game.execute();
}
