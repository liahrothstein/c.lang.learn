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

int compareSchools(const void *a, const void *b) {
    const struct School *s1 = (const struct School *)a;
    const struct School *s2 = (const struct School *)b;

    if ((s1 -> numberOfStudents) > (s2 -> numberOfStudents)) return -1;
    if ((s1 -> numberOfStudents) < (s2 -> numberOfStudents)) return 1;
    
    if ((s1 -> type) < (s2 -> type)) return -1;
    if ((s1 -> type) > (s2 -> type)) return 1;

    return 0;
};

void sortSchools(struct School schools[], int numberOfSchools) {
    qsort(schools, numberOfSchools, sizeof(struct School), compareSchools);
};

const char* typeToString(enum TypeOfSchool type) {
    switch (type) {
        case HighSchool:
            return "High School";
        case Gymnasium:
            return "Gymnasium";
        case Lyceum:
            return "Lyceum";
        case SpecializedSchool:
            return "Specialized School";
        case BoardingSchool:
            return "Boarding School";
        default:
            return "Unknown type";
    };
};

void printSchools(struct School schools[], int n) {
    printf("\nSchool Table:\n");
    printf("-------------------------------------------------------------------\n");
    printf("| %-17s | %-19s | %-21s |\n", "Number of School", "Number of Students", "Type");
    printf("-------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("| %-17d | %-19d | %-21s |\n",
            schools[i].numberOfSchool,
            schools[i].numberOfStudents,
            typeToString(schools[i].type)
        );
    };
    printf("-------------------------------------------------------------------\n");
};

int main() {
    char buffer[100];
    int i, j, arrayLength, inputType;
    bool isUnique;

    inputInteger(buffer, 100, &arrayLength, "number of schools");
    struct School schoolList[arrayLength];

    printf("\nFilling school data\n===================");
    for (i = 0; i < arrayLength; i++) {
        printf("\nSchool #%d", i+1);

        do {
            inputInteger(buffer, 100, &schoolList[i].numberOfSchool, "number of school");

            isUnique = true;
            for (j = 0; j < i; j++) {
                if (schoolList[i].numberOfSchool == schoolList[j].numberOfSchool) {
                    printf("\nError: Number of school is already exists");
                    isUnique = false;
                    break;
                }
            }
        } while (!isUnique);

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

    sortSchools(schoolList, arrayLength);

    printSchools(schoolList, arrayLength);

    return 0;
}