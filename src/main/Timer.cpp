#include "Timer.h"

#include <SDL.h>

void Timer::start(){
    started = true;
    paused = false;

    startTime = SDL_GetTicks();
    pausedTime = 0;
}

void Timer::stop(){
    started = false;
    paused = false;

    startTime = 0;
    pausedTime = 0;
}

void Timer::pause(){
    if (!(started && !paused)){
        return;
    }

    paused = true;
    pausedTime = SDL_GetTicks() + startTime;
    startTime = 0;
}

void Timer::resume() {
    if (!(started && paused)){
        return;
    }

    paused = false;

    startTime = SDL_GetTicks() + pausedTime;
    pausedTime = 0;
}

int Timer::getTicks(){
    if (started){
        return paused ? pausedTime : SDL_GetTicks() - startTime;
    }
    return 0;
}