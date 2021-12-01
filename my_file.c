#include "my_file.h"

#define MY_FILE_WRITE (O_CREAT | O_WRONLY | O_TRUNC)
#define MY_FILE_READ O_RDONLY

MY_FILE *my_fopen(const char *filename, const char *mode){
    MY_FILE *res = (MY_FILE *)calloc(1, sizeof(MY_FILE));
    struct stat st_buf;
    int flags = 0;
    if(mode[0] == 'w'){
        flags = MY_FILE_WRITE;
        res->buf = create_buffer(0);
        res->descriptor = open(filename, flags);
    }
    else if(mode[0] == 'r'){
        flags = MY_FILE_READ;
        if(stat(filename, &st_buf) == -1){
            free(res);
            return NULL;
        }
        res->size = st_buf.st_size;
        res->buf = create_buffer(res->size);
        res->cursor = 0;
        res->descriptor = open(filename, flags);
        ssize_t r = read(res->descriptor, res->buf.buf, res->size);
        res->buf.size = res->size;
        if(r < res->size){
            empty_buffer(&res->buf);
            free(res);
            return NULL;
        }
    }
    else{
        free(res);
        return NULL;
    }
    if(res->descriptor == -1){
        free(res);
        return NULL;
    }
    res->flags = flags;
    return res;
}

int my_getc(MY_FILE *stream){
    if(stream->cursor < stream->size){
        return (int)stream->buf.buf[stream->cursor++];
    }
    else{
        return EOF;
    }
}
int my_putc(uint8_t byte, MY_FILE *stream){
    append_to_buffer(&stream->buf, byte);
    stream->size++;
    stream->cursor++;
    return 0;
}

int my_fclose(MY_FILE *fp){
    if(fp->flags == MY_FILE_WRITE){
        write(fp->descriptor, fp->buf.buf, fp->size);
    }
    if(close(fp->descriptor) == -1) return -1;
    empty_buffer(&fp->buf);
    memset(fp, 0, sizeof(MY_FILE));
    free(fp);
    return 0;
}