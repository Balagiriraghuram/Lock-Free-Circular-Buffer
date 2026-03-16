#include "circular_buffer.h"

void cb_init(CircularBuffer *cb)
{
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
    cb->overrun = 0;
}

bool cb_is_empty(CircularBuffer *cb)
{
    return cb->count == 0;
}

bool cb_is_full(CircularBuffer *cb)
{
    return cb->count == BUFFER_SIZE;
}

bool cb_push(CircularBuffer *cb, uint8_t data)
{
    if (cb_is_full(cb)) {
        cb->overrun++;
        return false;
    }

    cb->buffer[cb->head] = data;
    cb->head = (cb->head + 1) % BUFFER_SIZE;
    cb->count++;

    return true;
}

bool cb_pop(CircularBuffer *cb, uint8_t *data)
{
    if (cb_is_empty(cb)) {
        return false;
    }

    *data = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % BUFFER_SIZE;
    cb->count--;

    return true;
}