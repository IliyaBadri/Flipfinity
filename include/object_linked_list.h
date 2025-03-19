#include "object.h"

typedef struct ObjectLinkedList_Node {
    Object* object;
    struct ObjectLinkedList_Node* next;
} ObjectLinkedList_Node;

ObjectLinkedList_Node* object_linked_list_create_node(Object* object);
void object_linked_list_append(ObjectLinkedList_Node** head, Object* object);
void object_linked_list_destroy(ObjectLinkedList_Node** head);
