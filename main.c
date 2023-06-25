/*manydice.c -- multiple dice rolls */
/*compile with diceroll.c */
#include <stdio.h>
#include <stdlib.h> /*for library srand() */
#include <time.h> /*for time() */
#include "diceroll.h" /*for roll_n_dice() */
#include "kolejka.h"

/*and for roll_count */
int main(void)
{
	int dice, roll;
	int sides;
    int status;
    int kolejki;
    
	srand((unsigned int) time(0)); /*randomize seed */

    //kolejki = kolejka();
	printf("Enter the number of sides per die, 0 to stop.\n");
    
	while (scanf("%d", &sides) == 1 && sides > 0)
	{
		printf("How many dice?\n");
		if ((status = scanf("%d", &dice)) != 1)
		{
			if (status == EOF)
            {    
                break; /*exit loop */}
			else
			{
				printf("You should have entered an integer.");
				printf(" Let's begin again.\n");
				while (getchar() != '\n')
					continue; /*dispose of bad input */
				printf("How many sides? Enter 0 to stop.\n");
				continue; /*new loop cycle */
			}
		}
        kolejki = kolejka();

        printf("Here are %d sets of %d %d-sided throws.\n",kolejki,dice,sides);
        for(int i=0; i<kolejki; i++)
		{
            roll = roll_n_dice(dice, sides);
		printf("%d  |  ", roll);
        }

        
		printf("\nHow many sides? Enter 0 to stop.\n");
	}

	printf("The rollem() function was called %d times.\n",
		roll_count); /*use extern variable */
	printf("GOOD FORTUNE TO YOU!\n");
	return 0;
}