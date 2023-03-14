# Linked list #
Generic linked list implementation in C. Can be used to store any custom data structure.

## How to use ##
To include header
```c
#include "linkedlist.h"
```
Structure example to store in the linked list
```c
typedef struct {
    int   any_int_field;
    char  any_char_field;
} any_structure_t;
```
Initialization. Must provide size of the elements to store
```c
linked_list_t list;
ll_init(&list, sizeof(any_structure_t));
```
Destruction
```c
ll_destroy(&list);
```
Element addition
```c
any_structure_t element;
element.any_int_field  = 5;
element.any_char_field = 'c';

ll_add(&list, &element);
```
Head deletion
```c
ll_delete_head(&list);
```
Tail deletion
```c
ll_delete_tail(&list);
```
List reversion
```c
ll_reverse(&list);
```
Get the number of elements in the list
```c
size_t length = list.length;
```
Element access and print example
```c
void print_list_example(linked_list_t ll) {
    node_t *       current = ll.head;
    any_structure_t *data;

    if (ll.head == NULL) {
        printf("[]\n");
    } else {
        printf("[");
        current = ll.head;
        data    = current->data;
        printf("int: %d, char: %c", data->any_int_field, data->any_char_field);
        while (current->next != NULL) {
            current = current->next;
            data    = current->data;
            printf("; int: %d, char: %c", data->any_int_field, data->any_char_field);
        }
        printf("]\n");
    }
}
```