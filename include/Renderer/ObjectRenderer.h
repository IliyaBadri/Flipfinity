#pragma once
#include "../Objects/SceneColorBackground.h"
#include <SDL3/SDL.h>
#include <string.h>
#include <stdio.h>

void RenderObject(SDL_Renderer* renderer, struct Object* object){
    if(renderer == NULL){
        fprintf(stderr, "Fatal error: NULL pointer renderer passed to include/Renderer/ObjectRenderer.h/RenderObject().\n");
        exit(EXIT_FAILURE);
        return;
    }
    if(object == NULL){
        fprintf(stderr, "Fatal error: NULL pointer object passed to include/Renderer/ObjectRenderer.h/RenderObject().\n");
        exit(EXIT_FAILURE);
        return;
    }

    if(object->sceneColorBackground != NULL){
        SDL_SetRenderDrawColor(renderer, object->sceneColorBackground->color.r, object->sceneColorBackground->color.g, object->sceneColorBackground->color.b, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer); 
        return;
    }
}