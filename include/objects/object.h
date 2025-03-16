#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "SDL3/SDL_pixels.h"

#include "../data/vector2.h"
#include "../data/color.h"

// Forward declarations child of structs
typedef struct Object_Transform Object_Transform;
typedef struct Object_ColorRectangle Object_ColorRectangle;
typedef struct Object_SceneColorBackground Object_SceneColorBackground;
typedef struct Object_Button Object_Button;

// Object Struct
typedef struct {    
    bool enabled;
    Object_Transform* transform;
    Object_ColorRectangle* color_rectangle;
    Object_SceneColorBackground* scene_color_background;
    Object_Button* button;
} Object;

// Child structs
struct Object_Transform{
    Object* parent;
    Vector2 position;
    Vector2 scale;
    float rotation;
};

struct Object_ColorRectangle{
    Object* parent;
    Color_RGBA color;
};

struct Object_SceneColorBackground{
    Object* parent;
    Color_RGBA color;
};

struct Object_Button{
    Object* parent;
};

// Generic object methods
Object* object_create(bool enabled, Object_Transform* transform, Object_ColorRectangle* color_rectangle, Object_SceneColorBackground* scene_color_background, Object_Button* button){
    Object* object = (Object*)malloc(sizeof(Object));
    object->enabled = enabled;
    object->transform = transform;
    object->color_rectangle = color_rectangle;
    object->scene_color_background = scene_color_background;
    object->button = button;
    return object;
}

void object_destroy(Object* object) {
    if(object->transform != NULL){
        free(object->transform);
    }
    if(object->color_rectangle != NULL){
        free(object->color_rectangle);
    }
    if(object->scene_color_background != NULL){
        free(object->scene_color_background);
    }
    if(object->button != NULL){
        free(object->button);
    }
    free(object);
}

// Other object methods
Object* object_create_scene_color_background(uint8_t red, uint8_t green, uint8_t blue) {
    Object_SceneColorBackground* scene_color_background = (Object_SceneColorBackground*)malloc(sizeof(Object_SceneColorBackground));
    scene_color_background->color.r = red;
    scene_color_background->color.g = green;
    scene_color_background->color.b = blue;
    scene_color_background->color.a = SDL_ALPHA_OPAQUE;
    Object* object = object_create(true, NULL, NULL, scene_color_background, NULL);
    scene_color_background->parent = object;
    return object;
}

Object* object_create_button(Vector2 position, Vector2 scale, Color_RGBA color) {
    Object_Transform* transform = (Object_Transform*)malloc(sizeof(Object_Transform));
    transform->position = position;
    transform->scale = scale;
    transform->rotation = 0.0f;
    Object_ColorRectangle* color_rectangle = (Object_ColorRectangle*)malloc(sizeof(Object_ColorRectangle));
    color_rectangle->color = color;
    Object_Button* button = (Object_Button*)malloc(sizeof(Object_Button));
    Object* object = object_create(true, transform, color_rectangle, NULL, button);
    transform->parent = object;
    color_rectangle->parent = object;
    button->parent = object;
    return object;
}
