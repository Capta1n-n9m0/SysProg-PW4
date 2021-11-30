#include <stdio.h>
#include "my_file.h"

int main(){
    MY_FILE *f = my_fopen("main.c", "r");

    my_fclose(f);
}