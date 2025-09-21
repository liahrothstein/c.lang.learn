#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isError = false;

double calculate(double num1, char op, double num2) {
    switch (op) {
        case '+' :
            return (num1 + num2);
        case '-' :
            return (num1 - num2);
        case '*' :
            return (num1 * num2);
        case '/' :
            if (num2 != 0) {
                return (num1 / num2);
            } else {
                printf("Error: division by zero\n");
                isError = true;

                return 0;
            }
            default:
                printf("Error: operator not found\n");
                isError = true;

                return 0;
    }
};

int main() {
    double number1, number2, result;
    char operation;

    printf("Hello User, this programm can add, subtract, multiply and divide two numbers and show you result\n");

    printf("Please type number one: ");
    scanf("%lf", &number1);
    
    printf("Please type operation: ");
    scanf(" %c", &operation);

    printf("Please type number two: ");
    scanf("%lf", &number2);

    result = calculate(number1, operation, number2);

    if (!isError) {
        printf("Result: %.2lf\n", result);
    };

    return 0;
}