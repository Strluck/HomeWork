#include <iostream>
#include "ArrayQueue.h"

int main()
{
    ArrayQueue q = *new ArrayQueue();
    for (int i = 0; i < 10; i++) {
        EnQueue(q, i);
    }
    int a;
    for (int i = 0; i < 10; i++) {
        DeQueue(q, a);
        printf("%d", a);
    }
}
