# SDL2_unexspected_Behavior_of_RenderPresent_reproducible

Minimal reproducible example for an unexspected behavior of the SDL_RenderPresent() function of the SDL2 2D rendering API

To reproduce the problem, clone the repository in new Folder and use mingw w64 gcc compiler with the command:
gcc code.c -Iinclude -Llibx64 -lSDL2main -lSDL2 -o code.exe

you should execute the code.exe via cmd to see the console output

the only diffrence between code and code2 is that code2 SDL_RenderPresents every step, while code only RenderPresents at the end
