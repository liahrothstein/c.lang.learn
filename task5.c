/*
Task 5 - Develop programm that transforms an array so that elements with odd indices come first, then elements with even indices, and the input data will come from the .in file and the result in .out
Author: Student Novikov D.A.
Date: 03.12.25
Ver: 02
*/

#include <stdio.h> /*import header file of input and output*/

#include "task5-arr-change.h"

int main() {
    int i; /*index*/
    int count; /*counter needed to calculate index of result array*/
    int arrayLength;

    scanf("%d", &arrayLength); /*scan array length*/
    
    int numArray[arrayLength];
    int resultNumArray[arrayLength];

    /*scan each element of array*/
    for (i = 0; i < arrayLength; i++) {
        scanf("%d", &numArray[i]);
    };

    printf("Hello user, this programm transforms an array so that elements with odd indices come first, then elements with even indices\n\n");

    printf("Initial number array:\n"); /*print all initial array*/
    for (i = 0; i < arrayLength; i++) {
        printf("%d ", numArray[i]);
    };
    
    arrChange(i, count, arrayLength, numArray, resultNumArray);
    
    printf("\n\nResult number array:\n"); /*print all result array*/
    for (i = 0; i < arrayLength; i++) {
        printf("%d ", resultNumArray[i]);
    };

    return 0;
}