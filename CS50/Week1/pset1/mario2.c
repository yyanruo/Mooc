#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void){
    int height= 0;
	
	// Grab user input, check it and ask for retry if not within bounds  
	do {
		printf("Height:");
		height = GetInt();
        if (height == 0)
        {
            return 0;
        }
	} while (height < 1 || height > 23);


	for(int i = 0; i <height; i++) 
	{
        for(int j = 0; j <height-i-1; j++)
        {
            printf("%s", " ");
        }
       
		for(int k = 0; k < i+1; k++)
		{
			printf("#");
		}
		printf("  ");
		for(int k = 0; k < i+1; k++)
		{
			printf("#");
		}
		printf("\n");
	}	

    return 0;
}