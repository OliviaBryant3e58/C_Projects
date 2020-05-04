#include <stdio.h>
#include <string.h>

void stretchMe(int value, char originalS[51], char stretchedS[151]);

int main() {

    char originalS[51] = {'\0'};
    char stretchedS[151] = {'\0'};
    int value;

    printf("Enter a word: ");
    scanf("%s", originalS);

    printf("\nEnter a number between 1 and 5: ");
    scanf("%d", &value);
    printf("\n");

    stretchMe(value, originalS, stretchedS);
    printf("%s\n", stretchedS);

    return 0;

}
//End Main

void stretchMe(int value, char originalS[51], char stretchedS[151]) {

    int i, length, position, j;

    length = strlen(originalS);
    position = 0;

    for (i = 0; i < length; i++) {

        stretchedS[position] = originalS[i];
        position++;

        if (i % 2 != 0) {

            for (j = 0; j < value - 1; j++) {

                stretchedS[position] = originalS[i];
                position++;

            }

        }

    }

    stretchedS[position] = '\0';

    return;

}
