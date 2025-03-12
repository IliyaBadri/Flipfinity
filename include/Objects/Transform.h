#pragma once
#include "Object.h"
#include "../Data/Vector2.h"

struct Transform {
    struct Object* parent;
    struct Vector2 position;
    struct Vector2 scale;
    float rotation;
};