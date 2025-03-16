#pragma once
#include "../objects/object.h"
#include <SDL3/SDL.h>
#include <string.h>
#include <stdio.h>

void renderer_render_object(SDL_Renderer* renderer, Object* object){
    if(renderer == NULL){
        fprintf(stderr, "Fatal error: NULL pointer renderer passed to include/Renderer/ObjectRenderer.h -> renderer_render_object().\n");
        exit(EXIT_FAILURE);
        return;
    }
    if(object == NULL){
        fprintf(stderr, "Fatal error: NULL pointer object passed to include/Renderer/ObjectRenderer.h -> renderer_render_object().\n");
        exit(EXIT_FAILURE);
        return;
    }

    if(object->scene_color_background != NULL){
        SDL_SetRenderDrawColor(renderer, object->scene_color_background->color.r, object->scene_color_background->color.g, object->scene_color_background->color.b, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer); 
        return;
    }
}