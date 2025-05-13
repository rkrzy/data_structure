//
// Created by 임준식 on 25. 5. 13.
//

#ifndef DATA_STRUCTURE_QUEUE_INTERFACE_H
#define DATA_STRUCTURE_QUEUE_INTERFACE_H
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100
typedef int element;

typedef struct Queue Queue;

typedef struct {
    void (*error)(char *message);
    void (*init_queue)(Queue *q);
    void (*queue_print)(Queue *q);
    int (*is_full)(Queue *q);
    int (*is_empty)(Queue *q);
    void (*en_queue)(Queue *q, element item);
    int (*de_queue)(Queue *q);
    void (*destroy)(Queue * q);
}QueueOps;

struct Queue {
    void * data;
    QueueOps * ops;
};

#endif //DATA_STRUCTURE_QUEUE_INTERFACE_H
