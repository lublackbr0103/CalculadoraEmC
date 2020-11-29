#include <stdio.h>
#include <stdbool.h>
#define MAX 100

int add(int x, int y){
    return x + y;
}

int main()
{
    while (true)
    {
        label:
        int a, b, result;
        char sum[MAX];
        char answer;

        scanf("%d", &a);
        scanf("%d", &b);

        result = add(a, b);

        printf("%d", result);

        printf("Continue? Y or N");

        if (answer == 'n' || answer == 'N')
        {
            break;
        }
        else
        {
            sum[result];
            goto label;
        }
        
    }
    return 0;
}