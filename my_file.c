#include "my_file.h"

MY_FILE *my_fopen(const char *filename, const char *mode){
    MY_FILE *res = (MY_FILE *)calloc(1, sizeof(MY_FILE));
    struct stat st_buf;
    int flags = 0;
    if(mode[0] == 'w'){
        flags = O_CREAT | O_WRONLY | O_TRUNC;
    }
    else if(mode[0] == 'r'){
        flags = O_RDONLY;
        if(stat(filename, &st_buf) == -1){
            free(res);
            return NULL;
        }
        res->size = st_buf.st_size;
    }
    else{
        free(res);
        return NULL;
    }
    res->descriptor = open(filename, flags);
    if(res->descriptor == -1){
        free(res);
        return NULL;
    }
    res->flags = flags;
    res->is_virgin = 1;
    return res;
}

int my_getc(MY_FILE *stream){
    if(stream->is_virgin){
        stream->buf = (char *)calloc(stream->size, 1);
        stream->cursor = 0;
        stream->is_virgin = 0;
        ssize_t r = read(stream->descriptor, stream->buf, stream->size);
        if(r < stream->size) return EOF;
        return stream->buf[stream->cursor++];
    }
    else{
        if(stream->cursor < stream->size){
            
        }
    }

    return 0;
}
int my_putc(int c, MY_FILE *stream){
    return 0;
}

int my_fclose(MY_FILE *fp){
    if(close(fp->descriptor) == -1) return -1;
    free(fp->buf);
    memset(fp, 0, sizeof(MY_FILE));
    free(fp);
    return 0;
}