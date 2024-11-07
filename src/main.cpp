#include <iostream>

#include <SDL3/SDL.h>
#include "render.h"

bool runing = true;

float old_time = 0;
int main(int argc, char *argv[])
{

    thread_test();

    SDL_Window *window; // Declare a pointer

    SDL_Init(SDL_INIT_VIDEO); // Initialize SDL3

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "An SDL3 window", // window title
        640,              // width, in pixels
        480,              // height, in pixels
        SDL_WINDOW_OPENGL // flags - see below
    );

    // Check that the window was successfully created
    if (window == NULL)
    {
        // In the case that the window could not be made...
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
    SDL_GLContext glcontext = SDL_GL_CreateContext(window);


    render_init();
    while (runing)
    {
        SDL_Event Event;
        while (SDL_PollEvent(&Event))
        {
            if (Event.type == SDL_EVENT_QUIT)
            {
                runing = false;
                break;
            }
        }

        float newTime = SDL_GetTicks();
        render_process(newTime - old_time);
        old_time = newTime;


        SDL_GL_SwapWindow(window);
    }

    render_end();

    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}