#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(char* characters)
{
    int answer = 0;
    for(int z = 0; characters[z] != '\0'; z++)
    {
        answer++;
    }
    return answer;
}

int my_num(char* characters)
{
    int number = 0;
    int cycle = 0;
    for(int z = 0; characters[z] != '\0'; z++)
    {
        if(characters[z] >= '0' && characters[z] <= '9')
        {
            number++;
        }
        cycle++;
    }
    if(cycle == number)
    {
        return 1;
    }
    return 0;
}

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

int* division(int number)
{
    // printf("number : %d\n", number);
    static int array[4] = {0};
       
    array[0] = (number / 1000);
    array[1] = (number / 100) % 10;
    array[2] = ((number / 10) % 100) % 10;
    array[3] = number % 10;

    return array;
}


int sycle(int size, char** arr)
{
    // printf("size: %d\n", size);
    // printf("arr[1]: %s\n", arr[1]);

    for(int n = 1; n != size; n++)
    {
        // printf("%s\n", arr[n]);
        if(my_strlen(arr[n]) == 2)
        {
            if(arr[n][0] == '-' && arr[n][1] == 't')
            {
                if(size >= n+1)
                {
                    if(my_num(arr[n+1]) > 0)
                    {
                        return atoi(arr[n+1]);
                    }
                }
            }
        }
    }

    return 10;
} 