/*
Task 6 - Develop programm 
Author: Student Novikov D.A.
Date: 06.10.25
Ver: 01
*/

#include <stdio.h> /*import header file of input and output*/
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

enum TypeOfSchool {
    HighSchool = 1,
    Gymnasium = 2,
    Lyceum = 3,
    SpecializedSchool = 4,
    BoardingSchool = 5
};

struct School { /*structure is analogue of object*/
    int numberOfSchool;
    int numberOfStudents;
    enum TypeOfSchool type;
};

int isInteger(const char *str) { /*check integer number*/
    char *endptr;
    strtol(str, &endptr, 10);

    return (*endptr == '\0');
};

void inputInteger(char buffer[], size_t bufferSize, int *num, char inputValue[]) {
    int wordLength = strlen(inputValue);
    int i;

    while (true) {
        printf("\n\nPlease type %s: ", inputValue);

        fgets(buffer, bufferSize, stdin); /*input integer number*/
        buffer[strcspn(buffer, "\n")] = '\0'; /*delete '\n'*/
        
        if ((isInteger(buffer)) && (atoi(buffer) > 0)) {
            *num = atoi(buffer); /*convert string to integer*/

            break;
        } else {
            printf("Error: The %s is a natural and integer number", inputValue);

            continue;
        }
    };
};

void sortSchools(struct School sortedSchools[], int numberOfSchools) {
    int i, n;
    struct School school;

    for (n = 1; n < numberOfSchools; n++) {
        for (i = 0; i < numberOfSchools; i++) {
            if (i != (numberOfSchools - 1)) {
                if ((sortedSchools[i].numberOfStudents) < (sortedSchools[i + 1].numberOfStudents)) {
                    school = sortedSchools[i];
                    sortedSchools[i] = sortedSchools[i + 1];
                    sortedSchools[i + 1] = school;
                }
            }
        }
    };
};

int main() {
    char buffer[100];
    int i, arrayLength, inputType;

    inputInteger(buffer, 100, &arrayLength, "number of schools");
    struct School schoolList[arrayLength], sortedSchools[arrayLength];

    printf("\nFilling school data\n===================");
    for (i = 0; i < arrayLength; i++) {
        printf("\nSchool #%d", i+1);

        inputInteger(buffer, 100, &schoolList[i].numberOfSchool, "number of school");

        inputInteger(buffer, 100, &schoolList[i].numberOfStudents, "number of students");

        while (true) {
            printf("\n\n________________________________\n|Name              |Input Value|\n================================\n|High School       |1          |\n|Gymnasium         |2          |\n|Lyceum            |3          |\n|Specialized School|4          |\n|Boarding School   |5          |\n‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾");
            inputInteger(buffer, 100, &inputType, "type of school");
            if ((inputType >= HighSchool) && (inputType <= BoardingSchool)) {
                schoolList[i].type = (enum TypeOfSchool) inputType;

                break;
            } else {
                printf("\nError: Uncorrect type of school");
                
                continue;
            }
        };
    };

    sortedSchools[arrayLength] = schoolList[arrayLength];
    sortSchools(sortedSchools, arrayLength);

    return 0;
}