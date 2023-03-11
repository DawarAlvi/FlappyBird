#include "Entity.h"

// TODO: create texture pool to avoid loading same texture multiple times

Entity::Entity() {}

Entity::Entity(SDL_Renderer* renderer, const char* texturePath)
	: renderer(renderer), texture(IMG_LoadTexture(renderer, texturePath)) {
	SDL_QueryTexture(texture, NULL, NULL, &src.w, &src.h);
	dest = src;
}

Entity::Entity(SDL_Renderer* renderer, const char* texturePath, SDL_Rect dest_rect)
	: renderer(renderer), texture(IMG_LoadTexture(renderer, texturePath)),dest(dest_rect) {
	SDL_QueryTexture(texture, NULL, NULL, &src.w, &src.h);
}

Entity::Entity(SDL_Renderer* renderer, const char* texturePath, SDL_Rect src_rect, SDL_Rect dest_rect)
	: renderer(renderer), texture(IMG_LoadTexture(renderer, texturePath)), src(src_rect), dest(dest_rect) {

}

void Entity::Update() { }

void Entity::Render()
{
	SDL_RenderCopy(renderer, texture, &src, &dest);
}
