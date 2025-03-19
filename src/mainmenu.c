#include "mainmenu.h"

#include <stdio.h>
#include <stdlib.h>

#include "object.h"
#include "renderer.h"

void mainmenu_update(SDL_Renderer *renderer){
    if(renderer == NULL){
        fprintf(stderr, "Fatal error: NULL pointer renderer passed to include/scenes/mainmenu.h -> mainmenu_update().\n");
        exit(EXIT_FAILURE);
        return;
    }
    Object* green_background_object = object_create_scene_color_background(0, 69, 0);
    renderer_render_object(renderer, green_background_object);
}