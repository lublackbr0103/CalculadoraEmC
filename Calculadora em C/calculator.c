#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include "calc.h"

int main() {

    float firstValue, secondValue, result;
    char input_firstValue[100], input_secondValue[100];
    char operation;
    char operations[5] = {'+', '-', '*', '/'};
    bool key = true;
    setlocale(LC_ALL, "");

    while (true) {

        // "-- SIMPLE CALC --"
        intro();      

        while (true){

            fflush(stdin);

            arithmeticError_Control:
            // Get arithmetic operator from user
            do
            {
                show_operation(); scanf("%c", &operation);

                for (int i = 0; i < strlen(operations); i++)
                {
                        if (operation == '+' || operation == '-' || operation == '*' || operation == '/')
                        {
                                key = false;
                                break;
                        }
                        else
                        {
                                fflush(stdin);
                                error();
                                break;
                        }
                }
            } while (key);


            inputError_Control:
            
            // Getting first value from user
            while (true) {
                
                fflush(stdin);
                printf("FIRST VALUE: ");
                fgets(input_firstValue, sizeof(input_firstValue), stdin);
                sscanf(input_firstValue, "%f", &firstValue);

                int scanning = find(input_firstValue); /* Verify if there is any comma in input */

                if (scanning) {
                    break;
                }
            }

            if (!(sscanf(input_firstValue, "%f", &firstValue))){
                goto Invalid_input;
            }

            // Getting second value from user
            while (true) {
                
                fflush(stdin);
                printf("SECOND VALUE: ");
                fgets(input_secondValue, sizeof(input_secondValue), stdin);
                sscanf(input_secondValue, "%f", &secondValue);

                int scanning = find(input_secondValue);

                if (scanning) {
                    break;
                }
            }

            if (!(sscanf(input_secondValue, "%f", &secondValue))) {
                goto Invalid_input;
            }

            // Validate input if it is a floating point number
            if (sscanf(input_firstValue, "%f", &firstValue) && sscanf(input_secondValue, "%f", &secondValue)) {
                break;
            }
            
            // Continue the loop while user not enter a float number
            Invalid_input:
                printf("Invalid input!\nPlease enter only numbers...\n");
                sleep(1);
                goto inputError_Control;
        }

        switch (operation)
        {
        case '+':
            result = sum(strtof(input_firstValue, NULL), strtof(input_secondValue, NULL));
            break;
        case '-':
            result = sub(strtof(input_firstValue, NULL), strtof(input_secondValue, NULL));
            break;
        case '*':
            result = mult(strtof(input_firstValue, NULL), strtof(input_secondValue, NULL));
            break;
        case '/':
            result = mult(strtof(input_firstValue, NULL), strtof(input_secondValue, NULL));
            break;
        default:
            printf("Enter a valid operator!\n");
            sleep(1);
            goto arithmeticError_Control;
            break;
        }  

        // Printing the result on Screen
        space();
        printf("First Value: %.2f\n", firstValue);
        printf("Second Value: %.2f\n", secondValue);
        printf("\nRESULT: %.2f\n", result);
        space();

        // Condition to continue the program
        while (true) {

            fflush(stdin);
            char answer;
            
            space();
            printf("Want to Continue Y or N?: ");
            //getchar();
            scanf(" %c", &answer);

            if (answer == 'y' || answer == 'Y') {
                system("cls");
                break;
            }
            else if (answer == 'n' || answer == 'N') {
                printf("Finishing program...");
                sleep(1);
                goto exit;
            }
            else {
                printf("Wrong answer! Try again\n");
                sleep(1);
                //system("cls");
                continue;
            }
        }
    }

    system("pause");
    
    exit:
    return 0;
}