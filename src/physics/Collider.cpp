#include "Collider.h"

int World::chunkSize = 256;
std::vector<std::vector<Chunk>> World::chunks;

Collider::Collider()
{
    // default constructor
    this->shape.x = 0;
    this->shape.y = 0;
    this->shape.w = 32;
    this->shape.h = 32;
    this->size = Vector2(32.f, 32.f);
    centerPosition = Vector2(
        this->shape.x + (this->size.x / 2),
        this->shape.y + (this->size.y / 2)
    );
    this->isStatic = true;
}

Collider::Collider(Node *_p)
{
    // node constructor
    this->position = _p->getGlobalPosition();
    this->globalPosition = _p->getGlobalPosition();
    this->size = _p->getSize();
    this->updateRectBounds();
}

Collider::Collider(Entity *_p)
{
    // entity collider constructor
    this->position = _p->getGlobalPosition();
    this->globalPosition = _p->getGlobalPosition();
    this->size = _p->getSize();
    this->entity = _p;
    this->updateRectBounds();
}

void Collider::updateRectBounds()
{
    /*
        VOID UPDATE RECT BOUNDS:

        -update rect position & size

        -update centerposition variable
    */
    this->shape.x = (int)this->globalPosition.x;
    this->shape.y = (int)this->globalPosition.y;
    this->shape.w = (int)this->size.x;
    this->shape.h = (int)this->size.y;

    centerPosition = Vector2(
        this->shape.x + (this->size.x / 2),
        this->shape.y + (this->size.y / 2)
    );
}

void Collider::translate(Vector2 to)
{
    /*
        OVERRIDE VOID TRANSLATE:

        -check if parent is null

        -update node positions
        -force global position to be positive

        -update rect bounds

        -update children position
    */
    if (parent == nullptr)
    {
        return;
    }

    Vector2 next, nextGlobal;
    next = to;
    nextGlobal = to + this->getParent()->getGlobalPosition();

    if (nextGlobal.x < 0)
    {
        next.x = position.x;
    }
    if (nextGlobal.y < 0)
    {
        nextGlobal.y = 0;
        next.y = position.y;
    }

    this->globalPosition = nextGlobal;
    this->position = next;

    this->updateRectBounds();

    for (Node *n : children)
    {
        n->translate(n->getPosition());
    }
}

void Collider::setIsTrigger(bool _t)
{
    this->isTrigger = _t;
}

void Collider::setIsStatic(bool _s)
{
    this->isStatic = _s;
}

bool Collider::isColliding(Collider *other)
{
    /*
        BOOL IS COLLIDING:

        -return true if collider1 intersects with collider 2
        -pushes collider 1 back if 1 is an entity
    */
    bool r = SDL_HasIntersection(
        this->getShape(), other->getShape()
    );

    if (r && this->entity != nullptr && !this->isTrigger)
    {
        Vector2 force = (centerPosition - other->getCenter());
        entity->applyForce(force.normalized() * 16.f);
    }
    return r;
}

void Collider::render(SDL_Renderer *r)
{
    /*
        VOID RENDER:
        --used only for debugging--

        -draws collider shape, bounds and center point
    */
    SDL_Rect renderShape{
        shape.x,
        shape.y,
        shape.w,
        shape.h
    };

    SDL_SetRenderDrawColor(r, 123, 128, 255, 128);
    SDL_RenderFillRect(r, &renderShape);

    SDL_SetRenderDrawColor(r, 64, 64, 255, 255);
    SDL_RenderDrawRect(r, &renderShape);

    SDL_SetRenderDrawColor(r, 255, 0, 0, 255);
    SDL_RenderDrawPoint(
        r,
        centerPosition.x,
        centerPosition.y);
}

Vector2 Collider::getCenter()
{
    return this->centerPosition;
}

SDL_Rect * Collider::getShape()
{
    return &this->shape;
}