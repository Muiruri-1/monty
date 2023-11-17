#include <stdio.h>

int main() {
    char digit1, digit2;

    printf("Enter the first digit: ");
    scanf(" %c", &digit1);

    printf("Enter the second digit: ");
    scanf(" %c", &digit2);

    if (digit1 < '0' || digit1 > '9' || digit2 < '0' || digit2 > '9') {
        printf("Invalid input. Please enter digits.\n");
        return (1);
    }

    int result = (digit1 - '0') * (digit2 - '0');

    if (result >= 10) {
        printf("The product is not one digit long.\n");
    } else {
        printf("The product is: %d\n", result);
    }

    return (0);
}

