#pragma once

#include <stdlib.h>

typedef struct node {
    void *       data;
    struct node *next;
} node_t;

typedef struct {
    node_t *head;
    size_t  length;
    size_t  element_size;
} linked_list_t;

void    ll_init(linked_list_t *list, size_t element_size);
void    ll_destroy(linked_list_t *list);
node_t *ll_create_node(linked_list_t *list, void *data);
void    ll_add(linked_list_t *list, void *data);
void    ll_delete_head(linked_list_t *list);
void    ll_delete_tail(linked_list_t *list);
void    ll_reverse(linked_list_t *list);
