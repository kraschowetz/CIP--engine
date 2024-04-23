#pragma once

#include "../main/Node.h"
#include <SDL.h>

class Entity : public Node{

    //variables
    protected:
        float rotation;
        Vector2 size;
        Vector2 velocity;
        Vector2 externalForce;
        SDL_Rect rect;
    // functions
    public:
        Entity();
        void update(float delta);
        void render(SDL_Renderer* r);
        void applyForce(Vector2 force);
    // getters & setters
    public:
        Vector2 getPosition();
        SDL_Rect& getRect();


};