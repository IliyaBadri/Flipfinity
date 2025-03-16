#pragma once
#include <SDL3/SDL_render.h>
#include <stdio.h>
#include <stdlib.h>

enum Flipfinity_Scene {
    SCENE_MAIN_MENU
};

static Flipfinity_Scene current_scene = SCENE_MAIN_MENU;

void flipfinity_change_scene(Flipfinity_Scene new_scene){
    current_scene = new_scene;
}

// Update event handler for the whole game
void flipfinity_update(SDL_Renderer *renderer){
    if(renderer == NULL){
        fprintf(stderr, "Fatal error: NULL pointer renderer passed to include/flipfinity.h -> flipfinity_update().\n");
        exit(EXIT_FAILURE);
        return;
    }
}