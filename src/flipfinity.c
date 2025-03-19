#include "flipfinity.h"

#include <stdio.h>
#include <stdlib.h>

#include "mainmenu.h"

static Flipfinity_Scene current_scene = SCENE_MAIN_MENU;
static bool is_current_scene_started = false;

void flipfinity_change_scene(Flipfinity_Scene new_scene){
    current_scene = new_scene;
    is_current_scene_started = false;
}

void flipfinity_setup(){
    flipfinity_change_scene(SCENE_MAIN_MENU);
    is_current_scene_started = false;
}

void flipfinity_update(SDL_Renderer *renderer){
    if(renderer == NULL){
        fprintf(stderr, "Fatal error: NULL pointer renderer passed to include/flipfinity.h -> flipfinity_update().\n");
        exit(EXIT_FAILURE);
        return;
    }
    switch (current_scene)
    {
    case SCENE_MAIN_MENU:
        if(!is_current_scene_started){
            mainmenu_start();
            is_current_scene_started = true;
        }
        mainmenu_update(renderer);
        break;
    
    default:
        break;
    }
}