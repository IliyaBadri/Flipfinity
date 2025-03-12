#pragma once
#include "Object.h"
#include "../Data/Color.h"
#include <stdint.h>

struct ColorRectangle {
    struct Object* parent;
    struct RGBA color;
};