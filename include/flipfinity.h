#pragma once
#include <SDL3/SDL.h>

typedef enum Flipfinity_Scene {
    SCENE_MAIN_MENU
} Flipfinity_Scene;

static Flipfinity_Scene current_scene;
void flipfinity_change_scene(Flipfinity_Scene new_scene);
void flipfinity_setup();
void flipfinity_update(SDL_Renderer *renderer);
