#include <stdio.h>
#include "mmind.h"

int main(int size, char* array[])
{
    char* secret_code = scode(size, array);

    printf("secret code : %s\n", secret_code);
    
   
    int my_cycle = sycle(size, array);
    printf("my_cycle: %d\n", my_cycle);

    printf("Will you find the secret code?\n");
    printf("Please enter a valid guess\n");
    
    int round = 0;
    char* input_number;
    int well;
    int miss;


    for(int n = 0; n != my_cycle; n++)
    {
        
        printf("---\n");
        printf("Round %d\n", round);

        input_number = input();


        // printf("secret code : %s\n", secret_code);
        // printf("input number : %s\n", input_number);
        
    

        well = wellp(input_number, secret_code);
        miss = misp(input_number, secret_code);
        // printf("miss: %d\n", miss);
        // printf("well: %d\n", well);

        if(well == 4)
        {        
            printf("Congratz! You did it!\n");
            break;
        }

        printf("Well placed pieces: %d\n", well);
        printf("Misplaced pieces: %d\n", miss);
        
        round++;
    }

    return 0;
}