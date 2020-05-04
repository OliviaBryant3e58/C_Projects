#include <stdio.h>
//For Random Numbers
#include <stdlib.h>

int main (void) {

    //Variables

    int num = rand();

    float userGuess;

    //Guess

    printf("\nGuess a Random Number: ");
    scanf("%f", &userGuess);
    printf("\n");

    //if Statements

    if (userGuess < num) {
        printf("Guess a higher number.\n");
    }
    else if (userGuess > num) {
        printf("Guess a lower number.\n");
    }
    else {
        printf("You Guessed the Number!\n");
    }

    //Second Guess

    printf("\n");
    scanf("%f", &userGuess);
    printf("\n");

    if (userGuess == num) {
        printf("Congrats! You Guessed It!\n");
    }
    else {
        printf("You didn't guess it :(\n");
    }

return 0;

}
