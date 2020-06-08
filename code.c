#include <stdio.h>
#include <SDL.h> // c compiler linked to SDL2 (version 2.0.12) library is needed
#undef main
#include <time.h>
#include <Math.h>

int main(int argc, char* args[])
{
    //initialize stuff
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* win = SDL_CreateWindow("3D_Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 400,0);
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(rend, 255, 23, 255, 255);

    //start time measurement
    double t1, t2;
    t1 = (double)clock() / CLOCKS_PER_SEC;


    //run function 200 times
    for(int y = 0; y < 200; y++)
    { 
        for(int i = 0; i < 400; i++) // I figured it comes down to drawing a lot of points
            for(int j = 0; j < 400; j++)
                SDL_RenderDrawPoint(rend, i, j);
        SDL_RenderPresent(rend);  // program executes faster if this line is uncommented
    }
    SDL_RenderPresent(rend);

    //stop time measurement
    t2 = (double)clock() / CLOCKS_PER_SEC;

    //print time that the function took to execute 200 times and RenderPresent
    printf("%.4f \n", t2-t1); 

    //quit
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}