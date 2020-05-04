#include <stdio.h>

int main (void) {

    int choice;

    float area;
    float perimeter;

    int length;
    int width;

    do {

    printf("Enter Length in centimeters: ");
    scanf("%d", &length);

    } while (length <= 0);

    printf("\n");

    do {

    printf("Enter Width in cenimeters: ");
    scanf("%d", &width);

    } while(width <= 0);

    printf("\n");

    do {

    printf("Do you want to calculate area or perimeter?\n");
    printf("Enter (1 for area) or (0 for perimeter): ");
    scanf("%d", &choice);

    } while ( (choice < 0) || (choice > 1) );

    printf("\n");

    if (choice == 1) {

    area = length * width;

    printf("Area with length of %d and width of %d is: ", length, width);
    printf("%.2f\n", area);

    }

    else {

    perimeter = (length * 2) + (width * 2);

    printf("Perimeter with length of %d and width of %d is: ", length, width);
    printf("%.2f\n", perimeter);

    }



}
