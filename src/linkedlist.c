#include "linkedlist.h"
#include <string.h>

void ll_init(linked_list_t *list, size_t element_size) {
    list->head         = NULL;
    list->length       = 0;
    list->element_size = element_size;
}

void ll_destroy(linked_list_t *list) {
    node_t *current = list->head;
    node_t *next    = current;
    while (current != NULL) {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    list->head         = NULL;
    list->length       = 0;
    list->element_size = 0;
}

node_t *ll_create_node(linked_list_t *list, void *data) {
    node_t *new = malloc(sizeof(node_t));

    if (!new) {
        return NULL;
    }

    new->data = malloc(list->element_size);

    if (!new->data) {
        return NULL;
    }

    memcpy(new->data, data, list->element_size);

    new->next = NULL;

    return new;
}

void ll_add(linked_list_t *list, void *data) {
    node_t *current = NULL;

    if (list->head == NULL) {
        list->head = ll_create_node(list, data);
    } else {
        current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = ll_create_node(list, data);
    }

    list->length++;
}

void ll_delete_head(linked_list_t *list) {
    if (list->head != NULL) {
        node_t *head = list->head;
        list->head   = head->next;
        free(head->data);
        free(head);
        list->length--;
    }
}

void ll_delete_tail(linked_list_t *list) {
    if (list->head == NULL) {
        return;
    }

    node_t *current = NULL;

    if (list->length == 1) {
        current    = list->head;
        list->head = NULL;
        free(current->data);
        free(current);
        list->length = 0;
    } else {
        current          = list->head;
        node_t *previous = NULL;

        while (current->next != NULL) {
            previous = current;
            current  = current->next;
        }

        previous->next = NULL;
        free(current->data);
        free(current);
        list->length--;
    }
}

void ll_reverse(linked_list_t *list) {
    node_t *reversed = NULL;
    node_t *current  = list->head;
    node_t *temp     = NULL;

    while (current != NULL) {
        temp       = current;
        current    = current->next;
        temp->next = reversed;
        reversed   = temp;
    }

    list->head = reversed;
}