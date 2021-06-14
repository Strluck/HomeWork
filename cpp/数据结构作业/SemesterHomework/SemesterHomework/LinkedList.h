#include <stdlib.h>

typedef int ElemType; //ElemType

// linked_list 链表
typedef struct linked_list {
    int length;                     // 链表长度
    struct linked_list_node* first; // 首节点
} LinkedList;

// linked_list_node 链表节点
typedef struct linked_list_node {
    ElemType data;                 // 节点数据
    struct linked_list_node* next; // 下一个节点的内存地址
} LinkedListNode;


LinkedList NewList();                                  // 新建列表并且初始化
bool ListEmpty(LinkedList& list);                      // 链表是否为空
LinkedListNode* GetNode(LinkedList& list, int n);      // 获取节点 
bool ListInsert(LinkedList& list, int n, ElemType& e); // 插入元素
bool ListInsertB(LinkedList& list, ElemType& e);       // 向后插入元素
void ListClear(LinkedList& list);                      // 清空链表
void ListDestory(LinkedList* list);                    // 销毁链表