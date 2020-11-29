#include <stdio.h>

void sumMulti(int a, int b, int *sum, int *multi){
    *sum = a + b;
    *multi = a * b;
}

int main(){

    int a, b, sum, multi;

    scanf("%d", &a);
    scanf("%d", &b);

    sumMulti(a, b, &sum, &multi);

    printf("Sum: %d\tMulti: %d\n", sum, multi);

    return 0;
}