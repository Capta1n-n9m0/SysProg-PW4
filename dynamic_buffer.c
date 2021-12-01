#include "dynamic_buffer.h"

d_buffer create_buffer(uint32_t size){
    d_buffer res = {0};
    if(size == 0) size = BASE_BUFFER_SIZE;
    res.size = 0;
    res.cap = size;
    res.buf = (uint8_t *) calloc(size, 1);
    return res;
}

void empty_buffer(d_buffer *buffer){
    buffer->cap = 0;
    buffer->size = 0;
    free(buffer->buf);
    buffer->buf = NULL;
}

void append_to_buffer(d_buffer *buffer, uint8_t byte){
    if(buffer->size < buffer->cap){
        buffer->buf[buffer->size++] = byte;
    }
    else{
        buffer->cap += BASE_BUFFER_SIZE;
        buffer->buf = (uint8_t *) calloc(buffer->cap, sizeof(uint8_t));
        buffer->buf[buffer->size++] = byte;
    }
}


