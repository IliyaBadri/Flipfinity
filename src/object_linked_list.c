#include "object_linked_list.h"

#include <stdlib.h>
#include <stdio.h>

ObjectLinkedList_Node* object_linked_list_create_node(Object* object) {
    ObjectLinkedList_Node* node = (ObjectLinkedList_Node*)malloc(sizeof(ObjectLinkedList_Node));
    if(node == NULL){
        fprintf(stderr, "Fatal error: Memory allocation for node failed at src/object_linked_list.c -> object_linked_list_create_node().\n");
        exit(EXIT_FAILURE);
        return NULL;
    }
    node->object = object;
    node->next = NULL;
    return node;
}

void object_linked_list_append(ObjectLinkedList_Node** head, Object* object) {
    if(head == NULL){
        fprintf(stderr, "Fatal error: NULL pointer pointer head passed to src/object_linked_list.c -> object_linked_list_append().\n");
        exit(EXIT_FAILURE);
        return;
    }
    ObjectLinkedList_Node* new_node = object_linked_list_create_node(object);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    ObjectLinkedList_Node* temp = *head;
    while (temp->next != NULL){
        temp = temp->next;
    }
        
    temp->next = new_node;
}

void object_linked_list_destroy(ObjectLinkedList_Node** head) {
    if(head == NULL){
        fprintf(stderr, "Fatal error: NULL pointer pointer head passed to src/object_linked_list.c -> object_linked_list_destroy().\n");
        exit(EXIT_FAILURE);
        return;
    }
    if (*head == NULL) {
        return;
    }

    ObjectLinkedList_Node* current = *head;
    ObjectLinkedList_Node* next_node = NULL;

    while (current != NULL) {
        next_node = current->next;
        if (current->object != NULL) {
            object_destroy(current->object);
        }
        free(current);
        current = next_node;
    }

    *head = NULL;
}
