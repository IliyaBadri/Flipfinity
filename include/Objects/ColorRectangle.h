#pragma once
#include "Object.h"
#include "../Math/Color.h"

struct ColorRectangle {
    struct Object* parent;
    struct Color color;
};