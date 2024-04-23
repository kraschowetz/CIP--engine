#pragma once

#include <SDL.h>
#include <vector>
#include "../math/Vector2.h"

class Node
{
    // members
    protected:
        Vector2 globalPosition = Vector2();
        Vector2 position = Vector2();
        Vector2 size = Vector2(1.f, 1.f);
        Vector2 scale = Vector2(1.f, 1.f);
        Node *parent = nullptr;
        std::vector<Node*> children;
    // methods
    public:
        virtual void translate(Vector2 to);
        virtual void setSize(Vector2 to);
        virtual void update(float delta);
        virtual void render(SDL_Renderer *r);
        void addChild(Node *p);
        void updateChildren(float delta);
        void renderChildren(SDL_Renderer *r);
        void deleteNode();
        Vector2 getPosition();
        Vector2 getGlobalPosition();
        Vector2 getSize();
        Node *getParent();
        std::vector<Node *> getChildren();
};