#pragma once

#include <inttypes.h>
#include <stdlib.h>

#define BASE_BUFFER_SIZE 32

typedef struct{
    uint32_t cap;
    uint32_t size;
    uint8_t *buf;
} d_buffer;

d_buffer create_buffer(uint32_t size);
void empty_buffer(d_buffer *buffer);
void append_to_buffer(d_buffer *buffer, uint8_t byte);