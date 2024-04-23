#include "Node.h"

void Node::translate(Vector2 to)
{
    /*
        VOID TRANSLATE:

        -update self position

        -force global position to be positive

        -update children position
    */
    if (parent == nullptr)
    {
        return;
    }

    Vector2 next, nextGlobal;
    next = to;
    nextGlobal = to + this->getParent()->getGlobalPosition();
    
    if(nextGlobal.x < 0)
    {
        nextGlobal.x = 0;
        next.x = position.x;
    }
    if(nextGlobal.y < 0)
    {
        nextGlobal.y = 0;
        next.y = position.y;
    }
    

    this->globalPosition = nextGlobal;
    this->position = next;

    for (Node *n : children)
    {
        n->translate(n->getPosition());
    }
}

void Node::setSize(Vector2 to)
{
    this->size = to;
}

void Node::deleteNode()
{
    Node *parent = getParent();
    for (int i = 0; i < parent->getChildren().size(); i++)
    {
        if (parent->getChildren().at(i) == this)
        {
            for (Node *n : children)
            {
                n->deleteNode();
            }
            parent->children.erase(parent->children.begin() + i);
            delete this;
        }
    }
}

void Node::addChild(Node *p)
{
    p->parent = this;
    children.push_back(p);
}

void Node::update(float delta)
{
    updateChildren(delta);
}

void Node::updateChildren(float delta)
{
    for (Node *n : children)
    {
        n->update(delta);
    }
}

void Node::render(SDL_Renderer *r)
{
    renderChildren(r);
}

void Node::renderChildren(SDL_Renderer *r)
{
    for (Node *n : children)
    {
        n->render(r);
    }
}

Vector2 Node::getPosition()
{
    return this->position;
}

Vector2 Node::getGlobalPosition()
{
    return this->globalPosition;
}

Vector2 Node::getSize()
{
    return this->size;
}

Node *Node::getParent()
{
    return this->parent;
}

std::vector<Node *> Node::getChildren()
{
    return this->children;
}