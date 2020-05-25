// 一个简单的单链表实现

#include "LinkedList.h"

// NewList 新建列表并且初始化
LinkedList NewList() {
    LinkedList list = *new LinkedList;
    list.length = 0;
    list.first = NULL;
    return list;
}

// ListEmpty 链表是否为空
bool ListEmpty(LinkedList& list) {
    return list.length == 0;
}

// GetNode 获取节点 
LinkedListNode* GetNode(LinkedList& list, int n) {
    if (ListEmpty(list) || n < 1 || n > list.length) {
        return NULL;
    }
    // 获取首元节点
    LinkedListNode* node = list.first;
    for (int i = 1; i < n; i++) {
        node = node->next;
    }
    return node;
}

// ListInsert 插入元素
bool ListInsert(LinkedList& list, int n, ElemType& e) {
    // 新建节点(n)
    LinkedListNode* node = new LinkedListNode();
    node->data = e;
    node->next = NULL;

    if (n == 1) {
        // 更改首元节点
        node->next = list.first;
        list.first = node;
    }
    else {
        // 获取n的前一个(n-1)节点
        LinkedListNode* frontNode = GetNode(list, n - 1);
        if (frontNode == NULL) {
            return false;
        }
        // 插入节点(n)
        node->next = frontNode->next;
        frontNode->next = node;
    }

    list.length++;
    return true;
}

// ListInsertB 向后插入元素
bool ListInsertB(LinkedList& list, ElemType& e) {
    return ListInsert(list, list.length + 1, e);
}

// ListClear 清空链表
void ListClear(LinkedList& list) {
    if (ListEmpty(list)) {
        return;
    }

    LinkedListNode* node = list.first;
    LinkedListNode* barkNode;
    do {
        barkNode = node->next;
        delete node;
        node = barkNode;
    } while (node);

    list.first = NULL;
    list.length = 0;
}

// ListDestory 销毁链表
void ListDestory(LinkedList* list) {
    ListClear(*list);
    delete list;
}