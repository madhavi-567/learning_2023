#include <stdio.h>

int main() {
    float num1, num2, result;
    char operator;

    // Read Operand 1
    printf("Enter Operand 1: ");
    scanf("%f", &num1);

    // Read Operator
    printf("Enter Operator (+, -, *, /): ");
    scanf(" %c", &operator);

    // Read Operand 2
    printf("Enter Operand 2: ");
    scanf("%f", &num2);

    // Perform the calculation based on the operator
    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            // Check for division by zero
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                printf("Error: Division by zero is not allowed.\n");
                return 1; // Exit the program with an error code
            }
            break;
        default:
            printf("Error: Invalid operator.\n");
            return 1; // Exit the program with an error code
    }

    // Print the result
    printf("Result: %.2f\n", result);

    return 0;
}