#include "Sprite.h"

void Sprite::load(std::string path, SDL_Renderer *r)
{
    image = IMG_Load(path.c_str());
    texture = SDL_CreateTextureFromSurface(r, image);
}

void Sprite::render(SDL_Renderer *r)
{
    SDL_Rect dstrect = {
        (int)position.x,
        (int)position.y,
        (int)(size.x * scale.x),
        (int)(size.y * scale.y)};
    SDL_RenderCopy(r, texture, NULL, &dstrect);
}