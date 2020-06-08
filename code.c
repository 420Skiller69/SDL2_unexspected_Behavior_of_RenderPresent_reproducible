#include <stdio.h>
#include <SDL.h>
#undef main
#include <time.h>
#include <Math.h>

void drawCircle(SDL_Renderer *rend, int x, int y, int radius)
{
    for(int i = x-radius; i < x+radius; i++)
		for(int j = y-radius; j < y+radius; j++) 
			// if( sqrt(pow(i-x,2)+pow(j-y,2)) < radius )
				SDL_RenderDrawPoint(rend, i, j);
}
// void drawCircle2(SDL_Renderer *rend, int x, int y, int radius)
// {
// 	for(int i = 0; i < 2*radius;i++)
// 	{
// 		SDL_Rect r;
// 		int c = sqrt(pow(radius, 2) - pow(i-radius,2));
// 		r.x = x - c;
// 		r.y = y + i - radius;
// 		r.w = 2 * c;
// 		r.h = 1;
// 		SDL_RenderFillRect(rend, &r);
// 	}
// }
int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* win = SDL_CreateWindow("3D_Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000,0);
	SDL_Renderer* rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

	double t1, t2;

	SDL_SetRenderDrawColor(rend, 255, 23, 255, 255);
	t1 = (double)clock() / CLOCKS_PER_SEC;


	for(int y = 0; y < 300; y++)
	{ 
		drawCircle(rend,500,500,200);
	
		// SDL_RenderPresent(rend);
	}
		SDL_RenderPresent(rend);

	t2 = (double)clock() / CLOCKS_PER_SEC;

	printf("%.4f \n", t2-t1); 

    //quit
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
	SDL_Quit();

	return 0;
}
