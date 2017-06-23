#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int shower;
    int bottles;
 
    printf("How many minutes is your shower?");
    shower = GetInt();
    bottles = shower * 12;
    printf("Minutes: %i \nBottles: %i \n", shower, bottles);
    return 0;
}