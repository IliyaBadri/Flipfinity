#pragma once
#include "../Objects/SceneColorBackground.h"
#include <SDL3/SDL.h>
#include <string.h>

void RenderObject(SDL_Renderer* renderer, struct Object* object){
    if(renderer == NULL || object == NULL){
        return;
    }
    if(object->sceneColorBackground != NULL){
        SDL_SetRenderDrawColor(renderer, object->sceneColorBackground->color.r, object->sceneColorBackground->color.g, object->sceneColorBackground->color.b, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer); 
        return;
    }
}