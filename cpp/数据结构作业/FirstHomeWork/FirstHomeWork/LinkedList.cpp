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

// GetElem ��ȡԪ��
Status GetElem(LinkedList& list, int n, ElemType& e) {
    LinkedListNode* node = GetNode(list, n);
    if (node == NULL) {
        return ERROR;
    }
    e = node->data;

    return OK;
}

// LocateELem ����Ԫ��
LinkedListNode* LocateELem(LinkedList& list, ElemType& e) {
    LinkedListNode* node = list.first;
    // �����ң�ֱ���ҵ���һ��e��nodeΪ��(0)ʱ����
    while (node && e != node->data) {
        node = node->next;
    }

    return node;
}

// ListInsert ����Ԫ��
Status ListInsert(LinkedList& list, int n, ElemType& e) {
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
            return ERROR;
        }
        // ����ڵ�(n)
        node->next = frontNode->next;
        frontNode->next = node;
    }

    list.length++;
    return OK;
}

// ListInsertNode ����ڵ�
Status ListInsertNode(LinkedList& list, int n, LinkedListNode*& node) {
    if (n == 1) {
        // ������Ԫ�ڵ�
        node->next = list.first;
        list.first = node;
    }
    else {
        // ��ȡn��ǰһ��(n-1)�ڵ�
        LinkedListNode* frontNode = GetNode(list, n - 1);
        if (frontNode == NULL) {
            return ERROR;
        }
        // ����ڵ�(n)
        node->next = frontNode->next;
        frontNode->next = node;
    }

    list.length++;
    return OK;
}

// ListDelete ɾ��Ԫ��
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

        // �ж�λ��n�ϵ�Ԫ���Ƿ�Ϊ��
        if (NULL == frontNode->next) {
            return ERROR;
        }

        delete frontNode->next;
        frontNode->next = barkNode;
    }

    list.length--;
    return OK;
}

// ListClear ���˳���
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

// ArrayToLinkedList ������ת��Ϊ����
LinkedList ArrayToLinkedList(ElemType arr[], int len) {
    LinkedList list = NewList();
    ListInsertArray(list, arr, len);
    return list;
}

// ListInsertArray ��������Ԫ��
void ListInsertArray(LinkedList& list, ElemType arr[], int len) {
    int i = 0;
    LinkedListNode* node, * lastNode;

    if (ListEmpty(list)) {
        // ������Ԫ�ڵ�
        node = new LinkedListNode();
        node->data = arr[0];
        node->next = NULL;
        list.first = node;

        i++;
        list.length++;
        lastNode = node;
    }
    else {
        // �ӽ�β���룬��ȡ���һ���ڵ�
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
