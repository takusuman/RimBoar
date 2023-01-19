//header
#include "./game_application.hpp"

//builtin
#include <iostream>

//third party
#include <SDL.h>

void GameApplication::handle_input()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
            shall_quit = true;
        else if(event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                    shall_quit = true;
                    continue;
                
                default:
                    continue;
            }
        }
    }
}

void GameApplication::run()
{
    std::cout << "RimBoar lives!" << std::endl;

    while(!shall_quit)
    {
        this->handle_input();
        this->graphic_manager.render();
    }
    
}