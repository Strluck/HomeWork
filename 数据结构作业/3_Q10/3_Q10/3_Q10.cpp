#include "LinkedList.h"
#include <stdio.h>

void printList(LinkedList& list);
int getMaxInt(LinkedListNode* node);
int getLength(LinkedListNode* node);
int getMean(LinkedListNode* node, int len);

int main()
{
    printf("---------- 习题(10) ----------\n");
    int arr[5] = { 3,6,15,12,9 };
    LinkedList list = ArrayToLinkedList(arr, 5); // 将数组转换为单链表
    printList(list);                               // 打印单链表

    printf("Max: %d\n", getMaxInt(list.first));
    printf("Length: %d\n", getLength(list.first));
    printf("Mean: %d\n", getMean(list.first, getLength(list.first)));
}

// 获取最大整数
int getMaxInt(LinkedListNode* node) {
    if (node == NULL) {
        return 0;
    }

    int i;
    if (node->next == NULL) {
        i = 0;
    }
    else {
        i = getMaxInt(node->next);
    }

    if (node->data > i) {
        return node->data;
    }
    else {
        return i;
    }
}

int getLength(LinkedListNode* node) {
    if (node == NULL) {
        return 0;
    }
    int i;
    if (node->next == NULL) {
        i = 0;
    }
    else {
        i = getLength(node->next);
    }
    return ++i;
}

int getMean(LinkedListNode* node, int len) {
    if (node == NULL) {
        return 0;
    }
    int i;
    if (node->next == NULL) {
        i = 0;
    }
    else {
        i = getMean(node->next, len);
    }
    return i + node->data / len;
}


void printList(LinkedList& list) {
    LinkedListNode* node = list.first;
    printf("List地址: %p\n[\"%d\"", &list, node->data);
    node = node->next;
    while (node) {
        printf(",\"%d\"", node->data);
        node = node->next;
    }
    printf("]\n");
}