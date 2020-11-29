// include stdarg.h
// int fixed parameter
// define va_list variable
// begin and end the arg_list with va_start and va_end

#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

int add(int args, ...){
    va_list ap; //Argument parameter
    
    va_start(ap, args);

    // Process
    int count =0, sum = 0;
    for (count = 0; count < args; count++)
    {
        sum += va_arg(ap, int);
    }
    
    va_end(ap);
    return sum;
}

int main(){

    printf("%d", add(3, 1, 2, 3));

    return 0;
}
