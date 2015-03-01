#ifndef _main_H_
    #define _main_H_

#include <SDL2/SDL.h>
#include <math.h>
#include "stage.h"

class Main {
    public:

        static const int windowWidth = 800;
        static const int windowHeight = 600;

        Main( );
        int execute();

    private:

        bool running;

        SDL_Window* window;
        SDL_Renderer* renderer;

        void handleEvent( SDL_Event* event );

        bool initialize( );
        void render();
        void update( double dt );

        Stage stage;
};

#endif
