#include <stdio.h>

void read3Numbers(int * num1, int * num2, int * num3);
void add3Numbers(int num1, int num2, int num3, int * sum);

int main() {

    int num1, num2, num3, sum;

    read3Numbers(&num1, &num2, &num3);

    add3Numbers(num1, num2, num3, &sum);

    printf("The sum of the 3 numbers is: %d\n", sum);

    return 0;

}
//End Main

void read3Numbers(int * num1, int * num2, int * num3) {

    printf("Enter First Value: ");
    scanf("%d", num1);

    printf("Enter Second Value: ");
    scanf("%d", num2);

    printf("Enter Third Value: ");
    scanf("%d", num3);

    return;

}
//End read3Numbers

void add3Numbers(int num1, int num2, int num3, int * sum) {

    *sum = num1 + num2 + num3;

    return;

}
