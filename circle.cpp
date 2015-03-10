#include <iostream>
#include <unistd.h>
#include "circle.h"

Circle::Circle()
{

}

//void Circle::createFilledCircle(double mx, double my, double r)
//{
//    Uint32* pixbuf;
//    for (int y = -r; y < r; y++) {
//        pixbuf = (Uint32*)circle->pixels + circle->w * ((int)my + y) + ((int)mx - (int)r);
//        for (int x = -r; x < r; x++) {
//            if(x * x + y * y < r * r)
//                *(pixbuf++) = 0xffffffff;
//            else
//                *(pixbuf++) = 0x00000000;
//        }
//    }
//}

void Circle::createFilledCircle(double mx, double my, double r)
{
    int MSAA = 4;
    Uint32* pixbuf;
    for (int y = -r; y < r; y++) {
        pixbuf = (Uint32*)circle->pixels + circle->w * ((int)my + y) + ((int)mx - (int)r);
        for (int x = -r; x < r; x++) {
            if(x * x + y * y < r * r) {
                double buff;
                for (int p = 1; p < MSAA; p++) {
                    buff += 0xffffff00;
                }
                *(pixbuf++) = 0x000ffff0;
            } else
                *(pixbuf++) = 0x00000000;
        }
    }
}

SDL_Surface* Circle::getCircle()
{
    return circle;
}

void Circle::setCircle(SDL_Surface* s)
{
    circle = s;
}
