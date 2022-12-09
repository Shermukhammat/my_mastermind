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

//function for secret code
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

//function that returns rounds;
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

//function for well place;
int wellp(char* answer, char* correct_a)
{
    int count = 0;
	for(int n = 0; n != 4; n++)
	{
        printf("answer: %c correct : %c\n", answer[n], correct_a[n]);
		if(answer[n] == correct_a[n])
		{
			count++;
		}
	}
	
	return count;
}

//function for miss place;
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

//function for intput;
char* input()
{
    char answer[4];
    int sign = 1;
    char ram;
    int index = 0;
    int count = 0;

    //until the correct answer is entered;
    while (sign > 0)
    {
        //If incorrect information is entered;
        if(index > 0)
        {
            write(0, "Wrong input!\n", 13);
        }
        ram = ' ';
        write(0, ">", 1);
        int n;

        //Read all the information entered in the terminal and upload 4 characters to the answer
        for(n = 0; ram != '\n'; n++)
        {
            read(0, &ram, 1);
            // printf("%c ", ram);
            // printf("size: %d ", n);

            if(n < 4)
            {
                answer[n] = ram;
            }        
        }
        //If the entered information consists of 4 characters:
        if(n == 5)
        {
            count = 0;
            for(int i = 0; i != 4; i++)
            {
                //if each character of answer consists of a character from 0 to -> 8:
                if(answer[i] >= '0' && answer[i] <= '8')
                {
                    count++;
                }
            }
            //return the answer;
            if(count == 4)
            {
                break;
            }
            //otherwise prompt for re-entry;
            else 
            {
                sign++;
            }
        }
        //therwise, ask to enter the information again;
        else 
        {
            sign++;
        }

        sign--;
        index++;
    }
    
    char* respons = answer;
    return respons;
}