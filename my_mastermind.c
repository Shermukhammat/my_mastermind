#include <stdio.h>
#include "mmind.h"

int main(int size, char* array[])
{
    char* secret_code = scode(size, array);
    printf("answer : %s\n", secret_code);
    
    int my_cycle = sycle(size, array);
    printf("my_cycle: %d\n", my_cycle);

    printf("Will you find the secret code?\n");
    printf("Please enter a valid guess\n");

    // int round = 0;
    // char input_number[4];
    // int well = 1;
    // int miss = 0;
    // for(int n = 0; n != my_cycle; n++)
    // {
    //     printf("---\n");
    //     printf("Round %d\n", round);

        input();
        
    //     well = wellp(inumber, scode_arr);
    //     miss = misp(inumber, scode_arr);

    //     if(well == miss && well != 0 && miss != 0)
    //     {        
    //         if(miss == 4 && well == 4) 
    //         {
    //         printf("Congratz! You did it!\n");
    //         break;
    //         }
            
    //     }

    //     printf("Well placed pieces: %d\n", well);
    //     printf("Misplaced pieces: %d\n", miss);
        
    //     round++;
    // }

    return 0;
}