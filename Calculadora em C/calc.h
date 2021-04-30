#include <stdio.h>

// "-- SIMPLE CALC --"
void intro(){
    printf("---------------------------------------");
    printf("-----------   SIMPLE CALC   -----------");
    printf("---------------------------------------");
    space();
    space();
    printf("= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =");
    printf("\nInsert the two values to calculate, then choose operation!\n");
    printf("\nTo calculate real numbers, please enter comma sign(,), instead dot sign(.)\n");
    printf("Example:\tEnter\t00,00\n\t\tInstead\t00.00\n");
    printf("= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =");    
    printf("\n\n");
}

void show_operation(){
        printf("What operation do you want to use?\n");
        printf("Sum\t\t\t+\n");
        printf("Subtraction\t\t-\n");
        printf("Multiplication\t\t*\n");
        printf("Division\t\t/\n");
}

// Add new line
void space(){
    printf("\n");
}

// Sum
float sum(float x, float y){    
    return x + y;
}

// Subtraction
float sub(float x, float y){
    return x - y;
}

// Multiplication
float mult(float x, float y){
    return x * y;
}

// Division
float divi(float x, float y){
    return x / y;
}

// Verify Char in Array
int find(char *x){

        for (int i = 0; i < sizeof(x); i++)
        {
            if (x[i] == '.')
            {
                printf("Please, insert comma!\n");
                sleep(1);
                break;
            }
            fflush(stdin);
        }
    }