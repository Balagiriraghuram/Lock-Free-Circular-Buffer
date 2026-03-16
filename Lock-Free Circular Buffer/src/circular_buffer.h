#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdint.h>
#include <stdbool.h>

#define BUFFER_SIZE 8

typedef struct {
    uint8_t buffer[BUFFER_SIZE];
    uint32_t head;
    uint32_t tail;
    uint32_t count;
    uint32_t overrun;
} CircularBuffer;

void cb_init(CircularBuffer *cb);
bool cb_push(CircularBuffer *cb, uint8_t data);
bool cb_pop(CircularBuffer *cb, uint8_t *data);

bool cb_is_empty(CircularBuffer *cb);
bool cb_is_full(CircularBuffer *cb);

#endif