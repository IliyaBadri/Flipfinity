#pragma once
#include "Object.h"
#include "../Data/Color.h"
#include "SDL3/SDL_pixels.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

struct SceneColorBackground {
    struct Object* parent;
    struct RGBA color;
};

struct Object* Object_CreateSceneColorBackground(uint8_t red, uint8_t green, uint8_t blue) {
    struct SceneColorBackground* sceneColorBackground = malloc(sizeof(struct SceneColorBackground));
    sceneColorBackground->color.r = red;
    sceneColorBackground->color.g = green;
    sceneColorBackground->color.b = blue;
    sceneColorBackground->color.a = SDL_ALPHA_OPAQUE;
    struct Object* object = Object_Create(true, NULL, NULL, sceneColorBackground);
    sceneColorBackground->parent = object;
    return object;
}