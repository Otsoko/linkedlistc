#include "linkedlist.h"
#include <stdint.h>
#include <stdio.h>

/**
 * @brief Structure for storing a timestamp using 6 bytes.
 * 
 */
typedef struct {
    uint32_t seconds; /**< Seconds */
    uint16_t millis;  /**< Milliseconds */
} jap_time_t;

/**
 * @brief Structure for storing IMU data.
 * 
 */
typedef struct {
    short      accel[3];  /**< Accelerometer data */
    short      gyro[3];   /**< Gyroscope data */
    jap_time_t timestamp; /**< Millis from 2019-01-01 00:00:00 GMT */
} jap_imudata_t;

void plength(linked_list_t ll) {
    printf("Length: %zd\n", ll.length);
}

void print_list(linked_list_t ll) {
    node_t *       current = ll.head;
    jap_imudata_t *data;

    if (ll.head == NULL) {
        printf("[]\n");
    } else {
        printf("[");
        current = ll.head;
        data    = current->data;
        printf("%d", data->timestamp.seconds);
        while (current->next != NULL) {
            current = current->next;
            data    = current->data;
            printf(", %d", data->timestamp.seconds);
        }
        printf("]\n");
    }
}

void print(linked_list_t ll) {
    plength(ll);
    print_list(ll);
    printf("\n");
}

int main(int argc, char const *argv[]) {
    linked_list_t ll;
    jap_imudata_t data;

    ll_init(&ll, sizeof(jap_imudata_t));
    print(ll);

    for (int i = 0; i < 11; i++) {
        data.timestamp.seconds = i;
        ll_add(&ll, &data);
        print(ll);
    }

    ll_reverse(&ll);
    print(ll);

    for (int i = 0; i < 6; i++) {
        ll_delete_head(&ll);
        print(ll);
    }

    for (int i = 0; i < 3; i++) {
        ll_delete_tail(&ll);
        print(ll);
    }

    ll_destroy(&ll);
    print(ll);

    printf("Size of node_t: %zd\n", sizeof(node_t));
    printf("Size of structure: %zd\n", sizeof(jap_imudata_t));

    return 0;
}
