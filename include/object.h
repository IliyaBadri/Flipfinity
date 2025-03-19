#pragma once
#include <stdbool.h>

#include "vector2.h"
#include "color.h"

// Forward declarations of object's children
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

// Object's children
struct Object_Transform{
    Object* parent;
    Vector2 position;
    Vector2 scale;
    float rotation;
};
struct Object_SceneColorBackground{
    Object* parent;
    Color_RGBA color;
};

struct Object_ColorRectangle{
    Object* parent;
    Color_RGBA color;
};

struct Object_Button{
    Object* parent;
};

// Generic object methods
Object* object_create(bool enabled, Object_Transform* transform, Object_ColorRectangle* color_rectangle, Object_SceneColorBackground* scene_color_background, Object_Button* button);
void object_destroy(Object* object);

// Object's children methods
Object* object_create_scene_color_background(uint8_t red, uint8_t green, uint8_t blue);
Object* object_create_button(float position_x, float position_y, float scale_x, float scale_y, uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
