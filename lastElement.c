#include <stdio.h>

int lastElement(int nov5Onwards[5][4], int chosenRow);

int main() {

    int returnVal;
    int chosenRow;
    int nov5Onwards[5][4] = {

        {5, 12, 19, 26},
        {6, 13, 20, 27},
        {7, 14, 21, 28},
        {8, 15, 22, 29},
        {9, 16, 23, 30}

    };

    do {

        printf("Enter a number between 0 and 4: ");
        scanf("%d", &chosenRow);

    } while((chosenRow != 0) && (chosenRow != 1) && (chosenRow != 2) && (chosenRow != 3) && (chosenRow != 4));

    returnVal = lastElement(nov5Onwards, chosenRow);

    printf("Last number of chosen row in array: ");
    printf("%d\n", returnVal);

    return 0;

}
//End Main
//Start lastElement
int lastElement(int nov5Onwards[5][4], int chosenRow) {

    int returnVal;

    if (chosenRow == 0) {

        returnVal = nov5Onwards[0][3];

    }
    else if (chosenRow == 1) {

        returnVal = nov5Onwards[1][3];

    }
    else if (chosenRow == 2) {

        returnVal = nov5Onwards[2][3];

    }
    else if (chosenRow == 3) {

        returnVal = nov5Onwards[3][3];

    }
    else {

        returnVal = nov5Onwards[4][3];

    }

    return returnVal;

}
