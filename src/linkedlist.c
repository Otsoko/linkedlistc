#include "linkedlist.h"
#include <stdio.h>

void ll_init(linked_list_t *list) {
    list->head = NULL;
    list->size = 0;
}

void ll_destroy(linked_list_t *list) {
    node_t *current = list->head;
    node_t *next    = current;
    while (current != NULL) {
        next = current->next;
        //printf("free\n");
        free(current);
        //printf("freed\n");
        current = next;
    }
    list->head = NULL;
    list->size = 0;
}

node_t *ll_create_node(jap_imudata_t data) {
    node_t *new = malloc(sizeof(node_t));

    if (!new) {
        return NULL;
    }

    new->data = data;
    new->next = NULL;

    return new;
}

void ll_add(linked_list_t *list, jap_imudata_t data) {
    node_t *current = NULL;

    if (list->head == NULL) {
        list->head = ll_create_node(data);
    } else {
        current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = ll_create_node(data);
    }

    list->size++;
}

void ll_delete_head(linked_list_t *list) {
    if (list->head != NULL) {
        node_t *head = list->head;
        list->head   = head->next;
        free(head);
        list->size--;
    }
}