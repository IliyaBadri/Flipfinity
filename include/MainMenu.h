# pragma once
#include "Objects/SceneColorBackground.h"
#include "Renderer/ObjectRenderer.h"
#include <SDL3/SDL.h>
#include <string.h>
#include <stdio.h>

void RenderMainMenu(SDL_Renderer *renderer){
    if(renderer == NULL){
        fprintf(stderr, "Fatal error: NULL pointer renderer passed to include/MainMenu.h/RenderMainMenu().\n");
        exit(EXIT_FAILURE);
        return;
    }
    struct Object* greenBackGroundColor = Object_CreateSceneColorBackground(0, 69, 0);
    RenderObject(renderer, greenBackGroundColor);
}