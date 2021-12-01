#pragma once
#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include "dynamic_buffer.h"

// typedef struct{
//     int16_t descriptor;
//     uint64_t size;
//     uint16_t block_size;
//     uint32_t n_blocks;
//     int flags;
//     int is_virgin; /*If file has been entered.*/
//     uint64_t cursor;
//     uint32_t blocks_read;
//     char *buf;
//     FILE *file_pointer;
// } MY_FILE;
// screw it. i will just read whole file in one go.

typedef struct{
    int descriptor;
    ssize_t size;
    int flags;
    ssize_t cursor;
    d_buffer buf;
} MY_FILE;

//only 2 modes: r OR w
MY_FILE *my_fopen(const char *filename, const char *mode);
int my_getc(MY_FILE *stream);
int my_putc(uint8_t byte, MY_FILE *stream);
int my_fclose(MY_FILE *fp);

