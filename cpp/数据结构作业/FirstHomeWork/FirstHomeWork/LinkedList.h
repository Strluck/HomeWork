#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int Status;   //Status 是函数返回值类型，其值是函数结果状态代码。
typedef int ElemType; //ElemType 为可定义的数据类型，此设为int类型

// linked_list 单链表结构体 （头节点）
// 不设置头指针，单独设立头节点方便更换数据类型
typedef struct linked_list
{
    int length;                     // 长度
    struct linked_list_node* first; // 首元节点

} LinkedList;

// linked_list_node 单链表的节点结构体
typedef struct linked_list_node
{
    ElemType data;                 // 节点数据域
    struct linked_list_node* next; // 节点指针域，下一个节点

} LinkedListNode;

// 基础操作
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