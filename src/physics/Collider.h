#pragma once

#include <SDL.h>
#include "../entity/Entity.h"

class Collider : public Node
{
    //members
    private:
        SDL_Rect shape;
        bool isStatic;
        bool isTrigger = false;
        bool isActive = true;
        Vector2 centerPosition;
        Entity* entity;
    //getters
    public:
        SDL_Rect* getShape();
        Vector2 getCenter();
    // methods
    public:
        Collider();
        Collider(Node *_p);
        Collider(Entity* _p);
        void updateRectBounds();
        void translate(Vector2 to) override;
        void setIsTrigger(bool _t);
        void setIsStatic(bool _s);
        bool isColliding(Collider *other);
        void render(SDL_Renderer* r);
};

struct Chunk
{   
    static std::vector<Collider*> collisions;  
};

struct World
{
    static std::vector<std::vector<Chunk*>> chunks;
};
