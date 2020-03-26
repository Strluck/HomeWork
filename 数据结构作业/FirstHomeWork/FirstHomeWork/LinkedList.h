#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int Status;   //Status �Ǻ�������ֵ���ͣ���ֵ�Ǻ������״̬���롣
typedef int ElemType; //ElemType Ϊ�ɶ�����������ͣ�����Ϊint����

// linked_list ������ṹ�� ��ͷ�ڵ㣩
// ������ͷָ�룬��������ͷ�ڵ㷽�������������
typedef struct linked_list
{
    int length;                     // ����
    struct linked_list_node* first; // ��Ԫ�ڵ�

} LinkedList;

// linked_list_node ������Ľڵ�ṹ��
typedef struct linked_list_node
{
    ElemType data;                 // �ڵ�������
    struct linked_list_node* next; // �ڵ�ָ������һ���ڵ�

} LinkedListNode;

// ��������
LinkedList NewList();
bool ListEmpty(LinkedList& list);
LinkedListNode* GetNode(LinkedList& list, int n);
Status GetElem(LinkedList& list, int n, ElemType& e);
LinkedListNode* LocateELem(LinkedList& list, ElemType& e);
Status ListInsert(LinkedList& list, int n, ElemType& e);
Status ListInsertNode(LinkedList& list, int n, LinkedListNode*& node);
Status ListDelete(LinkedList& list, int n);
void ListClear(LinkedList& list);
void ListDestory(LinkedList* list);

LinkedList ArrayToLinkedList(ElemType arr[], int len);
void ListInsertArray(LinkedList& list, ElemType arr[], int len);