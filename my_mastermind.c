#include <stdio.h>
#include "mmind.h"

int main(int size, char* array[])
{
    int secret_code = scode(size, array);
    printf("javob : %d\n", secret_code);
    // int* scode_arr = division(secret_code);
    // printf("0:%d\n", scode_arr[0]);
    // printf("1:%d\n", scode_arr[1]);
    // printf("2:%d\n", scode_arr[2]);
    // printf("3:%d\n", scode_arr[3]);

    return 0;
}