#include <stdlib.h>
#define M 100

#define OK 1
#define ERROR 0

typedef int Status;   //Status 是函数返回值类型，其值是函数结果状态代码。
typedef int ElemType; //ElemType 为可定义的数据类型，此设为int类型

typedef struct array_queue
{
    int front;            // 头指针
    int rear;             // 尾指针
    ElemType array[M];
} ArrayQueue;

// 基础操作
ArrayQueue NewQueue(int len);
bool EnQueue(ArrayQueue& queue, ElemType& e);
bool DeQueue(ArrayQueue& queue, ElemType& e);