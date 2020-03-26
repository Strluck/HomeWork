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

// GetElem 获取元素
Status GetElem(LinkedList& list, int n, ElemType& e) {
    LinkedListNode* node = GetNode(list, n);
    if (node == NULL) {
        return ERROR;
    }
    e = node->data;

    return OK;
}

// LocateELem 查找元素
LinkedListNode* LocateELem(LinkedList& list, ElemType& e) {
    LinkedListNode* node = list.first;
    // 向后查找，直到找到第一个e或node为空(0)时结束
    while (node && e != node->data) {
        node = node->next;
    }

    return node;
}

// ListInsert 插入元素
Status ListInsert(LinkedList& list, int n, ElemType& e) {
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
            return ERROR;
        }
        // 插入节点(n)
        node->next = frontNode->next;
        frontNode->next = node;
    }

    list.length++;
    return OK;
}

// ListInsertNode 插入节点
Status ListInsertNode(LinkedList& list, int n, LinkedListNode*& node) {
    if (n == 1) {
        // 更改首元节点
        node->next = list.first;
        list.first = node;
    }
    else {
        // 获取n的前一个(n-1)节点
        LinkedListNode* frontNode = GetNode(list, n - 1);
        if (frontNode == NULL) {
            return ERROR;
        }
        // 插入节点(n)
        node->next = frontNode->next;
        frontNode->next = node;
    }

    list.length++;
    return OK;
}

// ListDelete 删除元素
Status ListDelete(LinkedList& list, int n) {
    if (n == 1) {
        LinkedListNode* node = list.first;
        list.first = node->next;
        delete node;
    }
    else {
        LinkedListNode* frontNode = GetNode(list, n - 1);
        if (frontNode == NULL) {
            return ERROR;
        }
        LinkedListNode* barkNode = frontNode->next->next;

        // 判断位置n上的元素是否为空
        if (NULL == frontNode->next) {
            return ERROR;
        }

        delete frontNode->next;
        frontNode->next = barkNode;
    }

    list.length--;
    return OK;
}

// ListClear 清空顺序表
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

// ArrayToLinkedList 将数组转化为链表
LinkedList ArrayToLinkedList(ElemType arr[], int len) {
    LinkedList list = NewList();
    ListInsertArray(list, arr, len);
    return list;
}

// ListInsertArray 插入数组元素
void ListInsertArray(LinkedList& list, ElemType arr[], int len) {
    int i = 0;
    LinkedListNode* node, * lastNode;

    if (ListEmpty(list)) {
        // 设置首元节点
        node = new LinkedListNode();
        node->data = arr[0];
        node->next = NULL;
        list.first = node;

        i++;
        list.length++;
        lastNode = node;
    }
    else {
        // 从结尾插入，获取最后一个节点
        lastNode = GetNode(list, list.length);
    }

    for (; i < len; i++) {
        node = new LinkedListNode();
        node->data = arr[i];
        lastNode->next = node;
        lastNode = node;

        list.length++;
    }
}
