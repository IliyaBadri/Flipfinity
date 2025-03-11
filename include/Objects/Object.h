#pragma once
#include "ColorRectangle.h"
#include "SceneColorBackground.h"
#include "Transform.h"
#include <stdbool.h>

struct Object {    
    bool enabled;
    struct Transform* transform;
    struct ColorRectangle* colorRectangle;
    struct SceneColorBackground* sceneColorBackground;
};