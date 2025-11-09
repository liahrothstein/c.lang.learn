/*
Task 1 - Develop programm processing a sequence of numbers with using "while" and without arrays
Author: Student Novikov D.A.
Date: 19.09.25
Ver: 01
*/

#include <stdio.h> /*import header file of input and output*/

const int true = 1;

int main() {
    int currentNum;
    int sum;

    printf("Hello user, this program calculates the sum of two-digit numbers\n\n");
    printf("Please type some number sequence\n");
    printf("For exit type number multiple of 8\n");

    while (true) {
        scanf("%d", &currentNum);
        
        if (currentNum > 9 && currentNum < 100) { /*check for positive numbers*/
            sum += currentNum;
        } else if (currentNum < -9 && currentNum > -100) { /*check for negative numbers*/
            sum += currentNum;
        };

        if ((currentNum % 8) == 0) {
            break;
        }
    };
    
    if (sum != 0) {
        printf("Sum all two-digit numbers: %d\n", sum);
    };

    return 0;
}