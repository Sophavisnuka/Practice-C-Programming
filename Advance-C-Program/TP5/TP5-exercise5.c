#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
//find factorial
long int factorial (int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
        printf("Factorial of : %d", factorial(n - 1));
    }
}
//find summation
long int summation (int n) {
    if (n <= 0) {
        return 0;
    } else {
        return n + summation(n - 1);
    }
}
//square root
void squareRoot () {
    int x;
    float square;
    printf("3. find the square root of an input number\n");
    printf("Input any number : ");
    scanf("%d", &x);
    if (x <= 0) {
        printf("That number must be bigger than 0\n");
    } else {
        square = sqrt(x);
        printf("Square root of %d : %.4f", x, square);
    }
}
//prime number
void primeNumber () {
    int number, prime = 1;
    printf("4. check if an input number is a prime number\n");
    printf("Enter number : ");
    scanf("%d", &number);
    for (int i = 2; i <= number; i++) {
        if (number % i == 0) {
            prime = 0;
            break;
        }   
        break;
    }
    if (number == 1 || prime == 0) {
        printf("%d is not a prime number.", number);
    } else if (number <= 0) {
        printf("Input positive number or number bigger than 0.");
    } else if (prime == 1) {
        printf("%d is a prime number.", number);
    }
}
//main function
int main () {
    int option, i, result;
    while (1) {
        system("cls");
        printf("1. compute factorial of an input number\n");
        printf("2. do summation of numbers from 1 to an input number\n");
        printf("3. find the square root of an input number\n");
        printf("4. check if an input number is a prime number\n");
        printf("5. exit the program\n");
        printf("choose any option : ");
        scanf("%d", &option);
        system("cls");
        switch (option)
        {
            case 1:
                printf("1. Compute factorial of an input number\n");
                printf("Input any number : ");
                scanf("%d", &i);
                printf("Factorial : %d", factorial(i));
                break;
            case 2:
                printf("2. do summation of numbers from 1 to an input number\n");
                printf("Input any number : ");
                scanf("%d", &i);
                result = summation(i);
                if (result == 1) {
                printf("The number that you input must bigger than 0\n");
                } else {
                    printf("Summation : %d", result);
                }
                break;
            case 3: 
                squareRoot();
                break;
            case 4:
                primeNumber();
                break;
            case 5: 
                exit (8);
            default:
                printf("Invalid option!\n");
            break;
        }
        printf("\nPress any key to go back....\n");
        getch();
    }
    return 0;
}