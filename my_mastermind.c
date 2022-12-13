#include <stdio.h>
#include "mmind.h"

int main(int size, char* array[])
{
    char* secret_code = scode(size, array);
    int my_cycle = sycle(size, array);

    printf("Will you find the secret code?\n");
    printf("Please enter a valid guess\n");

    char* input_number;
    int well;
    int miss;

    for(int n = 0; n < my_cycle; n++)
    {
        printf("---\nRound %d\n", n);
        input_number = input();

        // printf("secret code : %s\n", secret_code);
        // printf("input number : %s\n", input_number);
        
        well = wellp(input_number, secret_code);
        miss = misp(input_number, secret_code);

        if(well == 4)
        {        
            printf("Congratz! You did it!\n");
            break;
        }

        printf("Well placed pieces: %d\n", well);
        printf("Misplaced pieces: %d\n", miss);
    }

    return 0;
}