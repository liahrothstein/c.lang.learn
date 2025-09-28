/*
Task 2 - Develop programm that transforms an array so that elements with odd indices come first, then elements with even indices
Author: Student Novikov D.A.
Date: 21.09.25
Ver: 01
*/

#include <stdio.h> /*import header file of input and output*/

int numArray[20] = {51, 8, 98, 24, 35, 19, 33, 60, 88, 99, 8, 73, 57, 78, 52, 56, 8, 82, 24, 26};

int main() {
    int i; /*index*/
    int count; /*counter needed to calculate index of result array*/
    int arrayLength = sizeof(numArray) / sizeof(numArray[0]);
    
    int resultNumArray[arrayLength];

    printf("Hello user, this programm transforms an array so that elements with odd indices come first, then elements with even indices\n\n");

    printf("Initial number array:\n"); /*print all initial array*/
    for (i = 0; i < arrayLength; i++) {
        printf("%d ", numArray[i]);
    };
    
    count = 1; /*fill result array of numbers with odd indices*/
    for (i = count; i < arrayLength; i = i + 2) {
        resultNumArray[i - count] = numArray[i];
        count++;
    };
    count = (arrayLength / 2); /*fill result array of numbers with even indices*/
    for (i = 0; i < arrayLength; i = i + 2) {
        resultNumArray[count] = numArray[i];
        count++;
    };
    
    printf("\n\nResult number array:\n"); /*print all result array*/
    for (i = 0; i < arrayLength; i++) {
        printf("%d ", resultNumArray[i]);
    };

    return 0;
}