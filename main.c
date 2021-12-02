#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "my_file.h"

int main(){
    MY_FILE *f1 = my_fopen("foo1", "r");
    if(f1 == NULL){
        perror("foo1");
        exit(1);
    }
    MY_FILE *f2 = my_fopen("foo2", "r");
    if(f2 == NULL){
        perror("foo2");
        exit(1);
    }
    int c1, c2, len;
    len = f1->size;
    puts("\nfoo1");
    for(int i = 0; i < len; i++){
        c1 = my_getc(f1);
        printf("%c", c1);
    }
    puts("\nfoo2");
    for(int i = 0; i < len; i++){
        c2 = my_getc(f2);
        printf("%c", c2);
    }
    puts("");
    my_fclose(f1);
    my_fclose(f2);
    return 0;
}
