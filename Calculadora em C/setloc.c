#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(){

    char string[10];
    float result;

    printf("Enter a value: ");

    fgets(string, sizeof(string), stdin);
    // sscanf(string, "%s", &number);

    if (string[1] == ',' || string[2] == ',')
    {
        setlocale(LC_ALL, "");
    }
    else
    {
        setlocale(LC_ALL, "pt_BR");
    }

    printf("[String]Entered: %.2f\n", atof(string) + 2);

    return 0;
}