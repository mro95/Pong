#ifndef _bat_H_
    #define _bat_H_

#include <SDL2/SDL.h>

class Bat
{
    public:
        Bat(int x);
        void render( SDL_Renderer* renderer);
        void update( double dt );
        void control( int y );

    private:
        double targetY;
        double y;
        double dy;
        double x;
        double width;
        double height;
};

#endif
