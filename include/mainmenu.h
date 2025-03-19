# pragma once
#include <SDL3/SDL.h>
#include "object_linked_list.h"

static ObjectLinkedList_Node* mainmenu_objects_linked_list_head;

void mainmenu_start();
void mainmenu_update(SDL_Renderer* renderer);
