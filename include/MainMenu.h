# pragma once
#include "Objects/SceneColorBackground.h"
#include "Renderer/ObjectRenderer.h"
#include <SDL3/SDL.h>
#include <string.h>

void RenderMainMenu(SDL_Renderer *renderer){
    if(renderer == NULL){
        return;
    }
    struct Object* backgroundColorObject = Object_CreateSceneColorBackground(255, 0, 0);
    RenderObject(renderer, backgroundColorObject);
}