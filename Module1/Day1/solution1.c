#include <stdio.h>

int findBiggest(int num1, int num2) {
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}

int main() {
    int num1, num2;
    
    printf("Enter the first number: ");
    scanf("%d", &num1);
    
    printf("Enter the second number: ");
    scanf("%d", &num2);
    
    int biggest = findBiggest(num1, num2);
    
    printf("The biggest number is: %d\n", biggest);
    
    return 0;
}
