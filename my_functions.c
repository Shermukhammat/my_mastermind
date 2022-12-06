#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int scode(int size, char **arr)
{
    int answer = 0 ;
    // printf("size : %d \n", size);
    // printf("arr: %s\n", arr[1]);
    for(int n = 1; n != size; n++)
    {
        if(strlen(arr[n]) == 2)
        {
            // printf("1\n");
            if(arr[n][0] == '-' && arr[n][1] == 'c')
            {
                // printf("2\n");
                if(size >= n+1 && strlen(arr[n+1] ) == 4)
                {
                    // printf("3\n");
                    answer = atoi(arr[n+1]);
                    // printf("answer: %d\n", answer);
                    return answer;
                }
            }
        }
    }
    
    srand(time(NULL));
    while (0 == 0) 
    {
        answer = rand() % 9999;
        // printf("random answer: %d\n", answer);
        if(answer >= 1000 && answer <= 9999)
        {
            break;
        }
    }
    

    return answer;
}

// int* division(int number)
// {
//     printf("number : %d\n", number);
//     static int array[4] = {0, 0, 0, 0};

//     array[3] = number % 10;
//     array[2] = (number % 100) % 10;
    
//     return array;
// }