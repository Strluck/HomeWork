#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int Status;   //Status �Ǻ�������ֵ���ͣ���ֵ�Ǻ������״̬���롣
typedef char ElemType; //ElemType Ϊ�ɶ�����������ͣ�����Ϊint����

typedef struct simple_stack
{
    int length;                     // ����
    struct simple_stack_node* end;  // ĩβ�ڵ�

} SimpleStack;

typedef struct simple_stack_node
{
    ElemType data;                 // �ڵ�������
    struct simple_stack_node* next; // �ڵ�ָ������һ���ڵ�

} SimpleStackNode;

// ��������
SimpleStack NewStack();
bool StackEmpty(SimpleStack& stack);
void ClearStack(SimpleStack& stack);
bool DestoryStack(SimpleStack* list);
bool Push(SimpleStack& list, ElemType& e);
bool Pop(SimpleStack& list, ElemType& e);