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

char* my_random()
{
    static char answer[4];
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
    //This function accepts 4 numbers from the terminal using the -c command. 
    //If the numbers are entered incorrectly or not, it returns 4 numbers from 0 to 8;
    
    char* answer[4];
    char respons[4];
      
    //We look for the -c command;
    for(int n = 1; n != size; n++)
    {
        if(my_strlen(arr[n]) == 2)
        {
            if(arr[n][0] == '-' && arr[n][1] == 'c')
            {
                //If information is entered after -c command and consists of 4 characters;
                if(size >= n+1 && my_strlen(arr[n+1] ) == 4)
                {
                    //If characters 1 -> 8 are entered in reference;
                    for(int i = 0; i != 4; i++)
                    {
                        if(arr[n+1][i] >= '0' && arr[n+1][i] <= '8')
                        {                                                    
                            respons[i] = arr[n+1][i];
                        }
                        //Otherwise, return 4 random numbers from 0 to -> 8;
                        else 
                        {
                            *answer = my_random();
                            return *answer;
                        }
                    }
                    //Otherwise, return 4 random numbers from 0 to -> 8;
                    *answer = respons;
                    printf("\n");
                    printf("function answer: %s\n", *answer);
                    
                    return *answer;
                }
            }
        }
    }


    //Otherwise, return 4 random numbers from 0 to -> 8;
    *answer = my_random();
    return *answer;
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
    //We look for the -t command in the given array;
    for(int n = 1; n != size; n++)
    {
        if(my_strlen(arr[n]) == 2)
        {
            if(arr[n][0] == '-' && arr[n][1] == 't')
            {
                // If a number is entered after the -t command, return that number;
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

    // otherwise return 10;
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
    char answer[4] = " ";
    char depo[100] = " ";
    int index;
    char copy;
    int size;
    int count;
    for(int n = 0; n != 1; n++)
    {
        copy = ' ';
        size = 0;
        index = 0;
        
        write(0, ">", 1);
        for(int i = 0; copy != '\n'; i++)
        {
            read(0, &copy, 1);
            depo[index] = copy;
            // printf("coppy: <%c>\n", copy);

            size++;
            index++;
        }

        if(size != 5)
        {
            n--;
            printf("Wrong input!\n");
            continue;
        }


        count = 0;
        for(int z = 0; z != 4; z++)
        {
            printf("%d : %c\n ", z, depo[z]);
            if(depo[z] >= '0' && depo[z] <= '8')
            {
                count++;                
            }
        
        }
        if(count == 4)
        {
            answer[0] = depo[0];
            answer[1] = depo[1];
            answer[2] = depo[2];
            answer[3] = depo[3];
        }

        else 
        {
            n--;
            printf("Wrong input!\n");
            continue;
        }

        // printf("depo size: %d\n", size);
        // printf("depo: %s", depo);
    }
    printf("input answer: <%s>", answer);
     
    return NULL;
}