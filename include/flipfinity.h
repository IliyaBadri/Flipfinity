#pragma once
#include <SDL3/SDL_render.h>
#include <stdio.h>
#include <stdlib.h>

#include "./scenes/mainmenu.h"

typedef enum Flipfinity_Scene {
    SCENE_MAIN_MENU
} Flipfinity_Scene;

static Flipfinity_Scene current_scene = SCENE_MAIN_MENU;

void flipfinity_change_scene(Flipfinity_Scene new_scene){
    current_scene = new_scene;
}

// Setup event handler for the whole game
void flipfinity_setup() {
    flipfinity_change_scene(SCENE_MAIN_MENU);
}

// Update event handler for the whole game
void flipfinity_update(SDL_Renderer *renderer){
    if(renderer == NULL){
        fprintf(stderr, "Fatal error: NULL pointer renderer passed to include/flipfinity.h -> flipfinity_update().\n");
        exit(EXIT_FAILURE);
        return;
    }
    switch (current_scene)
    {
    case SCENE_MAIN_MENU:
        mainmenu_update(renderer);
        break;
    
    default:
        break;
    }
}