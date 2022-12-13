#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//FUNCTIONS FOR FUNCTIONS :)
int my_strlen(char* characters)
{
    int answer = 0;
    for(int z = 0; characters[z] != '\0'; z++)
    {
        answer++;
    }
    return answer;
}


char* my_random()
{
    char* answer=(char*)malloc(4*sizeof(char));
    int copy;
    srand(time(NULL));
    for(int n = 0; n != 4; n++)
    {
        copy = rand() % 9;
        copy += 48;
        
        answer[n] = copy; 
    }
   
    return answer;
}

//FOR THE MAIN FUNCTION
char* scode(int size, char **arr)
{
    char* answer = (char*) malloc(4 * sizeof(char));

    for(int n = 1; n != size; n++)
    {
        if(my_strlen(arr[n]) == 2 && arr[n][0] == '-' && arr[n][1] == 'c')
        {
            int count = 0;
            for(int i = 0; i != 4; i++)
            {                       
                if(arr[n+1][i] >= '0' && arr[n+1][i] <= '8')
                {                                                    
                    count++;
                }
                else 
                {                               
                    answer = my_random();
                    return answer;
                }
            }

            if(count == 4)
            {
                answer[0] = arr[n+1][0];
                answer[1] = arr[n+1][1];
                answer[2] = arr[n+1][2];
                answer[3] = arr[n+1][3];
                return answer;
            }
            answer = my_random();
            return answer;
        }
    }
    answer = my_random();
    return answer;
}


int sycle(int size, char** arr)
{
    for(int n = 1; n != size; n++)
    {
        if(my_strlen(arr[n]) == 2)
        {
            if(arr[n][0] == '-' && arr[n][1] == 't')
            {
                return atoi(arr[n+1]);
            }
        }
    }
    return 10;
} 


int wellp(char* answer, char* correct_a)
{
    int count = 0;
    for(int n = 0; n != 4; n++)
    {
        if(answer[n] == correct_a[n])
        {
            count++;
        }
    }

    return count;
}


int misp(char* answer, char* correct_a)
{
    int count = 0;
    for(int n = 0; n != 4; n++)
    {
        if(answer[n] != correct_a[n])
        {
            for(int i = 0; i != 4; i++)
            {
                if(answer[n] == correct_a[i])
                {
                    count++;
                }
            }
        }
    }

    return count;
}


char* input()
{
    char* depo = (char*) malloc(4 * sizeof(char));
    char ram;

    start:
        free(depo);
        ram = ' ';
        write(0, ">", 1);
        int n;
    
        for(n = 0; ram != '\n'; n++)
        {
            read(0, &ram, 1);
            

            if(n < 4)
            {
            }
                if(ram >= '0' && ram <= '8')
                {
                    // write(0,"|", 1);
                    depo[n] = ram;
                }   
                else
                {
                    write(0, "Wrong input!\n", 13);
                    goto start;
                }    
                        
        }
        return depo;
    // write(0, "Wrong input!\n", 13);
    goto start;
}