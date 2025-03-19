#include "object.h"

#include <stdlib.h>
#include <stdio.h>
#include <SDL3/SDL.h>

Object* object_create(bool enabled, Object_Transform* transform, Object_ColorRectangle* color_rectangle, Object_SceneColorBackground* scene_color_background, Object_Button* button){
    Object* object = (Object*)malloc(sizeof(Object));
    if(object == NULL){
        fprintf(stderr, "Fatal error: Memory allocation for object failed at src/object.c -> object_create().\n");
        exit(EXIT_FAILURE);
        return NULL;
    }
    object->enabled = enabled;
    object->transform = transform;
    object->color_rectangle = color_rectangle;
    object->scene_color_background = scene_color_background;
    object->button = button;
    return object;
}

void object_destroy(Object* object) {
    if(object->transform != NULL){
        object->transform = NULL;
        free(object->transform);
    }
    if(object->color_rectangle != NULL){
        object->color_rectangle = NULL;
        free(object->color_rectangle);
    }
    if(object->scene_color_background != NULL){
        object->scene_color_background = NULL;
        free(object->scene_color_background);
    }
    if(object->button != NULL){
        object->button = NULL;
        free(object->button);
    }
    free(object);
}

Object* object_create_scene_color_background(uint8_t red, uint8_t green, uint8_t blue) {
    Object_SceneColorBackground* scene_color_background = (Object_SceneColorBackground*)malloc(sizeof(Object_SceneColorBackground));
    if(scene_color_background == NULL){
        fprintf(stderr, "Fatal error: Memory allocation for scene_color_background failed at src/object.c -> object_create_scene_color_background().\n");
        exit(EXIT_FAILURE);
        return NULL;
    }
    scene_color_background->color.r = red;
    scene_color_background->color.g = green;
    scene_color_background->color.b = blue;
    scene_color_background->color.a = SDL_ALPHA_OPAQUE;
    Object* object = object_create(true, NULL, NULL, scene_color_background, NULL);
    scene_color_background->parent = object;
    return object;
}


Object* object_create_button(float position_x, float position_y, float scale_x, float scale_y, uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
    Object_Transform* transform = (Object_Transform*)malloc(sizeof(Object_Transform));
    if(transform == NULL){
        fprintf(stderr, "Fatal error: Memory allocation for transform failed at src/object.c -> object_create_button().\n");
        exit(EXIT_FAILURE);
        return NULL;
    }
    transform->position.x = position_x;
    transform->position.y = position_y;

    transform->scale.x = scale_x;
    transform->scale.y = scale_y;

    transform->rotation = 0.0f;
    Object_ColorRectangle* color_rectangle = (Object_ColorRectangle*)malloc(sizeof(Object_ColorRectangle));
    if(color_rectangle == NULL){
        fprintf(stderr, "Fatal error: Memory allocation for color_rectangle failed at src/object.c -> object_create_button().\n");
        exit(EXIT_FAILURE);
        return NULL;
    }
    color_rectangle->color.r = red;
    color_rectangle->color.g = green;
    color_rectangle->color.b = blue;
    color_rectangle->color.a = alpha;
    Object_Button* button = (Object_Button*)malloc(sizeof(Object_Button));
    if(button == NULL){
        fprintf(stderr, "Fatal error: Memory allocation for button failed at src/object.c -> object_create_button().\n");
        exit(EXIT_FAILURE);
        return NULL;
    }
    Object* object = object_create(true, transform, color_rectangle, NULL, button);
    transform->parent = object;
    color_rectangle->parent = object;
    button->parent = object;
    return object;
}