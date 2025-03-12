#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

struct Transform;
struct ColorRectangle;
struct SceneColorBackground;

struct Object* Object_CreateSceneColorBackground(uint8_t red, uint8_t green, uint8_t blue);

struct Object {    
    bool enabled;
    struct Transform* transform;
    struct ColorRectangle* colorRectangle;
    struct SceneColorBackground* sceneColorBackground;
};

struct Object* Object_Create(bool enabled, struct Transform* transform, struct ColorRectangle* colorRectangle, struct SceneColorBackground* sceneColorBackground){
    struct Object* object = malloc(sizeof(struct Object));
    object->enabled = enabled;
    object->transform = transform;
    object->colorRectangle = colorRectangle;
    object->sceneColorBackground = sceneColorBackground;
    return object;
}

void Object_Destroy(struct Object* object) {
    if(object->transform != NULL){
        free(object->transform);
    }
    if(object->colorRectangle != NULL){
        free(object->colorRectangle);
    }
    if(object->sceneColorBackground != NULL){
        free(object->colorRectangle);
    }
    free(object);
}