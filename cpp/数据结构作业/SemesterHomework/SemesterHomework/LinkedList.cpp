// һ���򵥵ĵ�����ʵ��

#include "LinkedList.h"

// NewList �½��б��ҳ�ʼ��
LinkedList NewList() {
    LinkedList list = *new LinkedList;
    list.length = 0;
    list.first = NULL;
    return list;
}

// ListEmpty �����Ƿ�Ϊ��
bool ListEmpty(LinkedList& list) {
    return list.length == 0;
}

// GetNode ��ȡ�ڵ� 
LinkedListNode* GetNode(LinkedList& list, int n) {
    if (ListEmpty(list) || n < 1 || n > list.length) {
        return NULL;
    }
    // ��ȡ��Ԫ�ڵ�
    LinkedListNode* node = list.first;
    for (int i = 1; i < n; i++) {
        node = node->next;
    }
    return node;
}

// ListInsert ����Ԫ��
bool ListInsert(LinkedList& list, int n, ElemType& e) {
    // �½��ڵ�(n)
    LinkedListNode* node = new LinkedListNode();
    node->data = e;
    node->next = NULL;

    if (n == 1) {
        // ������Ԫ�ڵ�
        node->next = list.first;
        list.first = node;
    }
    else {
        // ��ȡn��ǰһ��(n-1)�ڵ�
        LinkedListNode* frontNode = GetNode(list, n - 1);
        if (frontNode == NULL) {
            return false;
        }
        // ����ڵ�(n)
        node->next = frontNode->next;
        frontNode->next = node;
    }

    list.length++;
    return true;
}

// ListInsertB ������Ԫ��
bool ListInsertB(LinkedList& list, ElemType& e) {
    return ListInsert(list, list.length + 1, e);
}

// ListClear �������
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

// ListDestory ��������
void ListDestory(LinkedList* list) {
    ListClear(*list);
    delete list;
}