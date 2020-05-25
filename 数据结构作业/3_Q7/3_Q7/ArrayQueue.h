#include <stdlib.h>
#define M 100

#define OK 1
#define ERROR 0

typedef int Status;   //Status �Ǻ�������ֵ���ͣ���ֵ�Ǻ������״̬���롣
typedef int ElemType; //ElemType Ϊ�ɶ�����������ͣ�����Ϊint����

typedef struct array_queue
{
    int front;            // ͷָ��
    int rear;             // βָ��
    ElemType array[M];
} ArrayQueue;

// ��������
ArrayQueue NewQueue(int len);
bool EnQueue(ArrayQueue& queue, ElemType& e);
bool DeQueue(ArrayQueue& queue, ElemType& e);