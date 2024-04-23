#pragma once

#include <SDL.h>
#include <vector>

class InputHandler {
    //members
    private:
        std::vector<int> keysPressed;
        std::vector<int> keysJustPressed;
        std::vector<int> keysJustReleased;
    //methods
    public:
        void update();
        void pollEvents(SDL_Event e);
    //getters
    public:
        bool getKeyPressed(int k);
        bool getKeyJustPressed(int k);
        bool getKeyJustReleased(int k);
};