#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){

    float age;
    char input[99];

    while (true)
    {
        printf("Enter your age: ");

        fgets(input, sizeof(input), stdin);
        sscanf(input, "%f", &age);

        if (sscanf(input, "%f", &age)) {
            printf("You entered %.2f", age);
            sleep(1);
            break;
        }
        else {
            printf("Invalid input!\nPlease enter only numbers...\n");
            sleep(1);
            continue;
        }
    }

    printf("\n");
    system("pause");
    return 0;
}