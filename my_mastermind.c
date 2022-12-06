#include <stdio.h>
#include "mmind.h"

int main(int size, char* array[])
{
    int secret_code = scode(size, array);
    printf("javob : %d\n", secret_code);
    int* scode_arr = division(secret_code);
    
    

    return 0;
}