#include <stdio.h>
#include "mmind.h"

int main(int size, char* array[])
{
    int secret_code = scode(size, array);
    // printf("secret code : %d\n", secret_code);
    int* scode_arr = division(secret_code);
    
    printf("%d\n", scode_arr[0]);

    int my_cycle = sycle(size, array);

    printf("Will you find the secret code?\n");
    printf("Please enter a valid guess\n");

    int round = 0;
    int inumber = 0;
    for(int n = 0; n != my_cycle; n++)
    {
        restart:
            printf("---\n");
            printf("Round %d\n>", round);
            scanf("%d", &inumber);
            

            printf("Well placed pieces: %d\n", wellp(inumber, scode_arr));
            printf("Misplaced pieces: %d\n", misp(inumber, scode_arr));

            round++;
    }

    return 0;
}