#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <stdint.h>
#include <stdlib.h>

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

typedef struct node {
    jap_imudata_t data;
    struct node * next;
} node_t;

typedef struct {
    node_t *head;
    size_t  size;
} linked_list_t;

void    ll_init(linked_list_t *list);
void    ll_destroy(linked_list_t *list);
node_t *ll_create_node(jap_imudata_t data);
void    ll_add(linked_list_t *list, jap_imudata_t data);
void    ll_delete_head(linked_list_t *list);
void    ll_delete_tail(linked_list_t *list);
void    ll_reverse(linked_list_t *list);

#endif