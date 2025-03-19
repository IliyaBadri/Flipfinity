#include "mainmenu.h"

#include <stdio.h>
#include <stdlib.h>

#include "object.h"
#include "renderer.h"

static ObjectLinkedList_Node* mainmenu_objects_linked_list_head = NULL;

void mainmenu_start(){
    object_linked_list_destroy(&mainmenu_objects_linked_list_head);
    Object* green_background_object = object_create_scene_color_background(0, 69, 0);
    object_linked_list_append(&mainmenu_objects_linked_list_head, green_background_object);
}

void mainmenu_update(SDL_Renderer* renderer){
    ObjectLinkedList_Node* current_object_node = mainmenu_objects_linked_list_head;
    ObjectLinkedList_Node* next_object_node = NULL;
    while (current_object_node != NULL)
    {
        next_object_node = current_object_node->next;
        renderer_render_object(renderer, current_object_node->object);
        current_object_node = next_object_node;
    }
}