#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include "calc.h"

int main() {

    float a, b, result;
    char a_input[100], b_input[100];
    setlocale(LC_ALL, "");

    while (true) {

        // "-- SIMPLE CALC --"
        intro();      

        while (true){

            fflush(stdin);
            
            // Getting first value from user
            while (true) {
                
                printf("FIRST VALUE: ");
                fgets(a_input, sizeof(a_input), stdin);
                sscanf(a_input, "%f", &a);

                int scanning = find(a_input); /* Verify if there is any comma in input */

                if (scanning) {
                    break;
                }
            }

            if (!(sscanf(a_input, "%f", &a))){
                goto Invalid_input;
            }

            // Getting second value from user
            while (true) {
                
                printf("SECOND VALUE: ");
                fgets(b_input, sizeof(b_input), stdin);
                sscanf(b_input, "%f", &b);

                int scanning = find(b_input);

                if (scanning) {
                    break;
                }
            }

            if (!(sscanf(b_input, "%f", &b))) {
                goto Invalid_input;
            }

            // Validate input if it is a floating point number
            if (sscanf(a_input, "%f", &a) && sscanf(b_input, "%f", &b)) {
                break;
            }
            
            // Continue the loop while user not enter a float number
            Invalid_input:
                printf("Invalid input!\nPlease enter only numbers...\n");
                sleep(1);
                continue;
        }

        // Choosing operation
        char operation;
        label1:
        show_operation();
        scanf(" %c", &operation);
        getchar();        

        if (operation == '+') {
            result = sum(strtof(a_input, NULL), strtof(b_input, NULL));
        }
        else if (operation == '-') {
            result = sub(strtof(a_input, NULL), strtof(b_input, NULL));
        }
        else if (operation == '*')
        {
            result = mult(strtof(a_input, NULL), strtof(b_input, NULL));
        }
        else if (operation == '/')
        {
            result = divi(strtof(a_input, NULL), strtof(b_input, NULL));
        }
        else
        {
            printf("Enter a valid operator!\n");
            sleep(1);
            //system("cls");
            goto label1;
        }
        
        // Printing the result on Screen
        space();
        printf("First Value: %.2f\n", a);
        printf("Second Value: %.2f\n", b);
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