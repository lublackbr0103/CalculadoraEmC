#include <stdio.h>
#include <stdbool.h>

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


int main(){

    char name[20];
    char input[20];

    while (true)
    {
        printf("Name: ");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%s", &name);

        int scanning = find(&name);

        if (scanning)
        {
            break;
        }
        
        
    }

    system("pause");
    return 0;
}