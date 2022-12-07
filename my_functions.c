#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
        if(my_strlen(arr[n]) == 2)
        {
            // printf("1\n");
            if(arr[n][0] == '-' && arr[n][1] == 'c')
            {
                // printf("2\n");
                if(size >= n+1 && my_strlen(arr[n+1] ) == 4)
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

int wellp(int answer, int* correct_a)
{
    int array[4] = {0};
    int respons = 0;

    if(answer >= 1000 && answer <= 9999)
    {
        array[0] = (answer / 1000);
        array[1] = (answer / 100) % 10;
        array[2] = ((answer / 10) % 100) % 10;
        array[3] = answer % 10;

        for (int n = 0; n != 4; n++) 
        {
            if(array[n] == correct_a[n])
            {
                respons++;
            }
        }
    }

    return respons;
}

int misp(int answer, int* correct_a)
{
    int array[4] = {0};
    int respons = 0;

    if(answer >= 1000 && answer <= 9999)
    {
        array[0] = (answer / 1000);
        array[1] = (answer / 100) % 10;
        array[2] = ((answer / 10) % 100) % 10;
        array[3] = answer % 10;

        for(int n = 0; n != 4; n++)
        {
            for(int z = 0; z != 4; z++)
            {
                if(array[n] == correct_a[z])
                {
                    respons++;
                }
            }
        }
    }

    return respons;
}

void input(int *number)
{
    char copy;
    int mark = 0;
    while (mark == 0) 
    {
        copy = ' ';
        printf(">");
        for(int n = 0; copy != '\0'; n++)
        {
            write(0, &copy, 1);
            printf("%c", copy);
        }
    }

    *number = 0;
}

