#include <stdio.h>
#include "my_file.h"

int main(){
    MY_FILE *f1 = my_fopen("foo1", "r");
    MY_FILE *f2 = my_fopen("foo2", "r");
    int c1, c2;
    while((c2 = my_getc(f2)) != EOF){
        c1 = my_getc(f1);
        printf("%c %c  ", c1, c2);
    }
    puts("");
    my_fclose(f1);
    my_fclose(f2);
    return 0;
}
