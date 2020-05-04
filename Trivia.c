#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_QUESTIONS 7

//function prototypes

void promptPlayerForName(char [50]);
void printWelcomeMessage(char  [50]);
int  calculateCurrentAward(int, int);

void popUpCurrentQuestion4choices(int);
char askPlayerForLifeLine(void);
void popUpCurrentQuestion2choices(int);

char acceptPlayersFinalAnswer(void);
bool isCorrectFinalAnswer(char, int, char [MAX_QUESTIONS]);
void generateRandomGreeting(char [20]);

int calculateReducedAward(int, int);

//Start Main
int main() {

    char allCorrectAnswers[MAX_QUESTIONS + 1] = "CBCBACA";   // for my set of questions
    char greet[20];
    char nameForGame[50];

    int lifeLineUsed = 0;
    int questionNumber = 1;
    char playersResponseLifeLine;

    char finalAnswer;
    int currentAwardAmount;
    int reducedAmount;

    promptPlayerForName(nameForGame);

    printWelcomeMessage(nameForGame);

    while (questionNumber <= MAX_QUESTIONS) {

        currentAwardAmount = calculateCurrentAward(questionNumber, currentAwardAmount);

        popUpCurrentQuestion4choices(currentAwardAmount);

        if (lifeLineUsed == 0) {

            playersResponseLifeLine = askPlayerForLifeLine();

            if ((playersResponseLifeLine == 'Y') || (playersResponseLifeLine == 'y')) {

                popUpCurrentQuestion2choices(currentAwardAmount);
                lifeLineUsed++;
                printf("\nReminder - You get only 1 50-50 lifeline - and you are using it now \n\n");
            }

        }

        finalAnswer = acceptPlayersFinalAnswer();

        if (isCorrectFinalAnswer (finalAnswer, questionNumber, allCorrectAnswers)) {

            generateRandomGreeting(greet);
            printf("%s - You just won $ %d\n", greet, currentAwardAmount);

            if (questionNumber < MAX_QUESTIONS) {

                printf("Let us play the next question now\n\n");

            }

        }

        else {

            printf("Oops - that was incorrect.");

            reducedAmount = calculateReducedAward (questionNumber, currentAwardAmount);

            printf("You still won $%d. Well done.\n\n", reducedAmount);

            questionNumber = MAX_QUESTIONS;

        }

        questionNumber ++;

    }

    printf("It was fun playing with you \n\n");

    return 0;

}
//End Main

//Start promptPlayerForName
void promptPlayerForName(char nameForGame[50]) {

    char firstName[50] = {'\0'};
    char lastName[50] = {'\0'};

    //Input First Name

    printf("Enter your first name: ");
    scanf("%s", firstName);
    printf("\n");

    //Input Last Name

    printf("Enter your last name: ");
    scanf("%s", lastName);
    printf("\n");

    //Combine Names

    strcat(firstName, " ");
    strcat(firstName, lastName);

    strcpy(nameForGame, firstName);

    return;

}
//End promptPlayerForName

//Start printWelcomeMessage
void printWelcomeMessage(char nameForGame[50]) {

    printf("*\n**\n***\n***********************\n");
    printf("Welcome %s\n", nameForGame);
    printf("Let us play WDWM!\n");
    printf("***********************\n***\n**\n*\n");

}
//End printWelcomeMessage

//Start calculateCurrentAward
int calculateCurrentAward(int questionNumber, int currentAwardAmount) {

    if (questionNumber == 1) {

        currentAwardAmount = 100;

    }
    else if (questionNumber % 2 != 0) { //Calculate Odd Numbers

        currentAwardAmount = currentAwardAmount * 2;

    }
    else if (questionNumber % 2 != 1) { //Calculate Even Numbers

        currentAwardAmount = currentAwardAmount * 5;

    }

    return currentAwardAmount;

}
//End calculateCurrentAward

//Start popUpCurrentQuestion4choices
void popUpCurrentQuestion4choices(int currentAwardAmount) {

    if (currentAwardAmount == 100) { //Question 1

        printf("\n");

        printf("\nHere is the $100 question:\n");
        printf("Which of the following programming languages is taught in\n");
        printf("CIS 1500 at the University of Guelph?\n");

        printf("A. Python\tB.Cobra\nC. C\t\tD. Java\n");
        printf("\n");

    }
    else if (currentAwardAmount == 500) { //Question 2

        printf("\n");
        printf("\nHere is the $500 question:\n");
        printf("Which Canadian chain first opened in Hamilton in 1964?\n");

        printf("A. McDonalds\tB. Tim Hortons\nC. Wendy's\tD Mr.Sub\n");
        printf("\n");

    }
    else if (currentAwardAmount == 1000) { //Question 3

        printf("\n");
        printf("\nHere is the $1000 question:\n");
        printf("What is Canada's National sport?\n");

        printf("A. Hockey\t\t\tB. Lacrosse\nC. Hockey and Lacrosse\t\tD. BaseBall\n");
        printf("\n");

    }
    else if (currentAwardAmount == 5000) { //Question 4

        printf("\n");
        printf("\nHere is the $5000 question:\n");
        printf("Which Canadian city ranks as the most educated in the country?\n");

        printf("A. Montreal\t\tB. Ottawa\nC. Vancouver\t\tD. Toronto\n");
        printf("\n");

    }
    else if (currentAwardAmount == 10000) { //Question 5

        printf("\n");
        printf("\nHere is the $10 000 question:\n");
        printf("What is Canada's highest Mountain?\n");

        printf("A. Mount Logan, Yukon\t\t\tB. Whistler Mountain, BC\nC. Mont Tremblant, Quebec\t\tD. Tip Top Mountain, Ontario\n");
        printf("\n");

    }
    else if (currentAwardAmount == 50000) { //Question 6

        printf("\n");
        printf("\nHere is the $50 000 question:\n");
        printf("What is the easternmost province of Canada?\n");

        printf("A. Ontario\t\tB. Prince Edward Island\nC. Newfoundland\t\tD. Nova Scotia\n");
        printf("\n");

    }
    else if (currentAwardAmount == 100000) { //Question 7

        printf("\n");
        printf("\nHere is the $100 000 question:\n");
        printf("The southernmost point of mainland Canada is\ncalled Point Pelee. What province is it in?\n");

        printf("A. Ontario\t\tB. Quebec\nC. Newfoundland\t\tD. Nova Scotia\n");
        printf("\n");

    }

}
//End popUpCurrentQuestion4choices

//Start askPlayerForLifeLine
char askPlayerForLifeLine(void) {

    char playerAnswerLL;

    do {

        printf("\nWould you like to use a lifeline (50-50)?\n");

        printf("Enter Y or y, N or n: ");
        scanf(" %c", &playerAnswerLL);
        printf("\n");

    } while ((playerAnswerLL != 'Y') && (playerAnswerLL != 'y') && (playerAnswerLL != 'N') && (playerAnswerLL != 'n'));


    return playerAnswerLL;

}
//End askPlayerForLifeLine

//Start popUpCurrentQuestion2choices
void popUpCurrentQuestion2choices(int currentAwardAmount) {

    if (currentAwardAmount == 100) { //Question 1

        printf("\n");
        printf("OK - here are 2 choices after using the 50-50 Lifeline\n");
        printf("B. Cobra\nC. C\n");
        printf("\n");

    }
    else if (currentAwardAmount == 500) { //Question 2

        printf("\n");
        printf("OK - here are 2 choices after using the 50-50 lifeline\n");
        printf("A. McDonald's\nB. Tim Hortons\n");
        printf("\n");

    }
    else if (currentAwardAmount == 1000) { //Question 3

        printf("\n");
        printf("OK - here are 2 choices after using the 50-50 lifeline\n");
        printf("B. Lacrosse\nC. Hockey and Lacrosse\n");
        printf("\n");

    }
    else if (currentAwardAmount == 5000) { //Question 4

        printf("\n");
        printf("OK - here are 2 choices after using the 50-50 lifeline\n");
        printf("B. Ottawa\nC. Vancouver\n");
        printf("\n");

    }
    else if (currentAwardAmount == 10000) { //Question 5

        printf("\n");
        printf("OK - here are 2 choices after using the 50-50 lifeline\n");
        printf("A. Mount Logan, Yukon\nB. Whistler Mountain, BC\n");
        printf("\n");

    }
    else if (currentAwardAmount == 50000) { //Question 6

        printf("\n");
        printf("OK - here are 2 choices after using the 50-50 lifeline\n");
        printf("C. Newfoundland\nD. Nova Scotia\n");
        printf("\n");

    }
    else if (currentAwardAmount == 100000) { //Question 7

        printf("\n");
        printf("OK - here are 2 choices after using the 50-50 lifeline\n");
        printf("A. Ontario\nB. Quebec\n");
        printf("\n");

    }

}
//End popUpCurrentQuestion2choices

//Start acceptPlayersFinalAnswer
char acceptPlayersFinalAnswer(void) {

    char finalAnswer;

    do {

        printf("Enter your FINAL ANSWER ('A', 'B', 'C', or 'D') here: ");
        scanf(" %c", &finalAnswer);
        printf("\n");

    } while((finalAnswer != 'A') && (finalAnswer != 'B') && (finalAnswer != 'C') && (finalAnswer != 'D'));

    return finalAnswer;

}
//End acceptPlayersFinalAnswer

//Start isCorrectFinalAnswer
bool isCorrectFinalAnswer(char finalAnswer, int questionNumber, char allCorrectAnswers[MAX_QUESTIONS]) {

    int isCorrect;

    if (questionNumber == 1) { //Question 1

        if (finalAnswer == 'C') {

            isCorrect = 1;

        }
        else {

            isCorrect = 0;

        }

    }
    else if (questionNumber == 2) { //Question 2

        if (finalAnswer == 'B') {

            isCorrect = 1;

        }
        else {

            isCorrect = 0;

        }

    }
    else if (questionNumber == 3) { //Question 3

        if (finalAnswer == 'C') {

            isCorrect = 1;

        }
        else {

            isCorrect = 0;

        }

    }
    else if (questionNumber == 4) { //Question 4

        if (finalAnswer == 'B') {

            isCorrect = 1;

        }
        else {

            isCorrect = 0;

        }

    }
    else if (questionNumber == 5) { //Question 5

        if (finalAnswer == 'A') {

            isCorrect = 1;

        }
        else {

            isCorrect = 0;

        }

    }
    else if (questionNumber == 6) { //Question 6

        if (finalAnswer == 'C') {

            isCorrect = 1;

        }
        else {

            isCorrect = 0;

        }

    }
    else if (questionNumber == 7) { //Question 7

        if (finalAnswer == 'A') {

            isCorrect = 1;

        }
        else {

            isCorrect = 0;

        }

    }

    return isCorrect;

}
//End isCorrectFinalAnswer

//Start generateRandomGreeting
void generateRandomGreeting(char greet[20]) {

    int ranNum = rand() % 6; //Generate random number between 1 and 5

    if (ranNum == 1) {

        strcpy(greet, "Bravo!");

    }
    else if (ranNum == 2) {

        strcpy(greet, "Congrats!");

    }
    else if (ranNum == 3) {

        strcpy(greet, "Well Done!");

    }
    else if (ranNum == 4) {

        strcpy(greet, "Very Nice!");

    }
    else if (ranNum == 5) {

       strcpy(greet, "Proud of You!");

    }

    return;

}
//End generateRandomGreeting

//Start calculateReducedAward
int calculateReducedAward(int questionNumber, int currentAwardAmount) {

    if (questionNumber == 1) {

        currentAwardAmount = 0;

    }
    else if (questionNumber % 2 != 0) { //Odd Questions

        currentAwardAmount = currentAwardAmount - (currentAwardAmount / 2);

    }
    else if (questionNumber % 2 != 1) { //Even Questions

        currentAwardAmount = currentAwardAmount - (currentAwardAmount / 5);

    }

    return currentAwardAmount;

}
