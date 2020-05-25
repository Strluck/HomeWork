#include <stdio.h>
#include "SimpleStack.h"

int main()
{
    char str[] = "abeba";
    int len = 5;

    SimpleStack stack = NewStack();

    for (int i = 0; i < len/2; i++) {
        Push(stack, str[i]);
    }

    char c;
    int i;
    if (len % 2) {
        i = len / 2 + 1;
    }
    else {                       
        i = len / 2;                                 
    }                  
               
    while (!StackEmpty(stack)) {
        Pop(stack, c);
        //printf("%c %c \n", c, str[i]);
        if (c != str[i]) {                                          
            printf("N");
            return 0;
        } else {
            i++;
        }
    }                                                                                                        
i
    printf("Y");
    return 0;
}

