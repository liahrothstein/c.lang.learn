/*
Task 4 - Develop programm changes the input string so that between identical characters there is the '=' symbol and between different characters there is the '*' symbol
Author: Student Novikov D.A.
Date: 28.09.25
Ver: 01
*/

#include <stdio.h> /*import header file of input and output*/

char word[] = "successful"; /*initial string*/

void characterInsert(int index, int previousInd, char character, char initWord[], char changedWord[]) { /*function that insert special symbol*/
    changedWord[previousInd * 2] = word[previousInd];
    changedWord[index + previousInd] = character;
    changedWord[index * 2] = word[index];
};

int main() {
    int i; /*index*/
    int prevInd; /*previous index*/

    int wordLength = sizeof(word) / sizeof(word[0]);
    char transformedWord[wordLength * 2]; /*transformed string*/

    printf("Hello user, this program changes the input string so that between identical characters there is the '=' symbol and between different characters there is the '*' symbol\n\n");

    printf("Initial string: ");
    for (i = 0; i < wordLength; i++) {
        printf("%c", word[i]);
    };
    
    prevInd = 0;
    for (i = 1; i < wordLength - 1; i++) { /*fill each character to result string*/
        if (word[prevInd] == word[i]) {
            characterInsert(i, prevInd, "="[0], word, transformedWord);
        } else {
            characterInsert(i, prevInd, "*"[0], word, transformedWord);
        };
        
        prevInd++;
    };
    
    printf("\n\nTransformed string: ");
    for (i = 0; i < wordLength * 2; i++) {
        printf("%c", transformedWord[i]);
    };

    return 0;
}