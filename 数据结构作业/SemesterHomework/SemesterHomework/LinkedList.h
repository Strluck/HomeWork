#include <stdlib.h>

typedef int ElemType; //ElemType

// linked_list ����
typedef struct linked_list {
    int length;                     // ������
    struct linked_list_node* first; // �׽ڵ�
} LinkedList;

// linked_list_node ����ڵ�
typedef struct linked_list_node {
    ElemType data;                 // �ڵ�����
    struct linked_list_node* next; // ��һ���ڵ���ڴ��ַ
} LinkedListNode;


LinkedList NewList();                                  // �½��б��ҳ�ʼ��
bool ListEmpty(LinkedList& list);                      // �����Ƿ�Ϊ��
LinkedListNode* GetNode(LinkedList& list, int n);      // ��ȡ�ڵ� 
bool ListInsert(LinkedList& list, int n, ElemType& e); // ����Ԫ��
bool ListInsertB(LinkedList& list, ElemType& e);       // ������Ԫ��
void ListClear(LinkedList& list);                      // �������
void ListDestory(LinkedList* list);                    // ��������