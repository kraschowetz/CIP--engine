#pragma once

#include "Timer.h"
#include "InputHandler.h"
#include "Node.h"
#include "../physics/Collider.h" //

class Game
{
    // members
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        bool running = false;
        float deltaTime;
        Node *root;
        Node *e; //
    public:
        InputHandler input;
    // methods
    public:
        void start();
        void stop();

    private:
        void run();
        void pollEvents();
        void update(float delta);
        void render();
};