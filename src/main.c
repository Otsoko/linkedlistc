#include "linkedlist.h"
#include <stdio.h>

void psize(linked_list_t ll) {
    printf("Size: %zd\n", ll.size);
}

void print_list(linked_list_t ll) {
    node_t *current = ll.head;

    if (ll.head == NULL) {
        printf("[]\n");
    } else {
        printf("[");
        current = ll.head;
        printf("%d", current->data.timestamp.seconds);
        while (current->next != NULL) {
            current = current->next;
            printf(", %d", current->data.timestamp.seconds);
        }
        printf("]\n");
    }
}

void print(linked_list_t ll) {
    psize(ll);
    print_list(ll);
    printf("\n");
}

int main(int argc, char const *argv[]) {
    linked_list_t ll;
    node_t *      node;
    jap_imudata_t data;

    ll_init(&ll);
    print(ll);

    for (int i = 0; i < 11; i++) {
        data.timestamp.seconds = i;
        ll_add(&ll, data);
        print(ll);
    }

    ll_reverse(&ll);
    print(ll);

    for (int i = 0; i < 6; i++) {
        ll_delete_head(&ll);
        print(ll);
    }

    ll_destroy(&ll);
    print(ll);

    node = ll_create_node(data);
    free(node);

    printf("sizeof: %zd\n", sizeof(node_t));

    return 0;
}
