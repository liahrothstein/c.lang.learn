/*
Task 3 - Develop programm that transforms an array so that elements with odd indices come first, then elements with even indices, and with using pointers
Author: Student Novikov D.A.
Date: 21.09.25
Ver: 01
*/

#include <stdio.h> /*import header file of input and output*/

#include "../consts/num-array.c" /*import initial array*/

int main() {
    int i; /*index*/
    int count; /*counter needed to calculate index of result array*/

    int arrayLength = sizeof(numArray) / sizeof(numArray[0]);
    int *frstElPtrInit = numArray; /*first element pointer in an initial array*/
    
    int resultNumArray[arrayLength];
    int *frstElPtrRes = resultNumArray; /*first element pointer in a result array*/

    printf("Hello user, this programm transforms an array so that elements with odd indices come first, then elements with even indices\n\n");

    printf("Initial number array:\n"); /*print all initial array*/
    for (i = 0; i < arrayLength; i++) {
        printf("%d ", *(frstElPtrInit + i));
    };
    
    count = 1; /*fill result array of numbers with odd indices*/
    for (i = count; i < arrayLength; i = i + 2) {
        *(frstElPtrRes + i - count) = *(frstElPtrInit + i);
        count++;
    };
    count = (arrayLength / 2); /*fill result array of numbers with even indices*/
    for (i = 0; i < arrayLength; i = i + 2) {
        *(frstElPtrRes + count) = *(frstElPtrInit + i);
        count++;
    };
    
    printf("\n\nResult number array:\n"); /*print all result array*/
    for (i = 0; i < arrayLength; i++) {
        printf("%d ", *(frstElPtrRes + i));
    };

    return 0;
}