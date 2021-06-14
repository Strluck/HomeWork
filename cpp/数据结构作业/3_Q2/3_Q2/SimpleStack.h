#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int Status;   //Status 是函数返回值类型，其值是函数结果状态代码。
typedef char ElemType; //ElemType 为可定义的数据类型，此设为int类型

typedef struct simple_stack
{
    int length;                     // 长度
    struct simple_stack_node* end;  // 末尾节点

} SimpleStack;

typedef struct simple_stack_node
{
    ElemType data;                 // 节点数据域
    struct simple_stack_node* next; // 节点指针域，下一个节点

} SimpleStackNode;

// 基础操作
SimpleStack NewStack();
bool StackEmpty(SimpleStack& stack);
void ClearStack(SimpleStack& stack);
bool DestoryStack(SimpleStack* list);
bool Push(SimpleStack& list, ElemType& e);
bool Pop(SimpleStack& list, ElemType& e);