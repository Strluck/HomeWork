// https://github.com/Strluck/HomeWork

#include "LinkedList.h"
#include <stdio.h>

void printList(LinkedList& list);
int GetSortPosition(LinkedList& list, ElemType& e);
void ListMerge(LinkedList& list_1, LinkedList& list_2);
void ListIntersection(LinkedList& list_1, LinkedList& list_2);
int GetMaxNode(LinkedList& list, LinkedListNode*& maxNode);
void printList(LinkedList& list);

int main() {
    printf("---------- 习题(1) 合并 ----------\n");
    int arr_1[5] = { 3,6,9,12,15 };
    LinkedList list_1 = ArrayToLinkedList(arr_1, 5); // 将数组转换为单链表
    printList(list_1);                               // 打印单链表

    int arr_2[5] = { 1,3,5,7,9 };
    LinkedList list_2 = ArrayToLinkedList(arr_2, 5);
    printList(list_2);

    ListMerge(list_1, list_2); // 合并
    printList(list_1);

    printf("\n---------- 习题(3) 求交集 ----------\n");
    int arr_3[5] = { 3,6,9,12,15 };
    LinkedList list_3 = ArrayToLinkedList(arr_3, 5);
    printList(list_3);

    int arr_4[5] = { 1,3,5,7,9 };
    LinkedList list_4 = ArrayToLinkedList(arr_4, 5);
    printList(list_4);

    ListIntersection(list_3, list_4); // 求交集
    printList(list_3);

    printf("\n---------- 习题(6) 取最大值节点 ----------\n");
    int arr_5[10] = { 3,6,9,12,15,1,3,5,7,9 };
    LinkedList list_5 = ArrayToLinkedList(arr_5, 10);
    printList(list_5);

    LinkedListNode* node = new LinkedListNode();
    int maxPos = GetMaxNode(list_5, node); // 获取最大位置
    printf("最大值位置: %d\n最大值: %d\n", maxPos, node->data);

    return 0;
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

// GetSortPosition 获取顺序插入位置，return = 0 数据重复无需插入，return > 0 插入位置
int GetSortPosition(LinkedList& list, ElemType& e) {
    LinkedListNode* node = list.first;
    int i = 1;
    int n = 1;
    // 向后查找，直到找到第一个e或node为空(0)时结束
    while (node) {
        if (e == node->data) {
            return 0;
        }

        if (node->data < e) {
            n = i + 1;
        }

        node = node->next;
        i++;
    }

    return n;
}

/*
 * ListMerge 合并两个递增有序链表
 * 不重复数据(重复数据进行销毁)，复用内存空间
 * 合并后链表为 list_1, 合并后链表 list_1 依旧有序
 */
void ListMerge(LinkedList& list_1, LinkedList& list_2) {
    LinkedListNode* node = list_2.first;
    LinkedListNode* barkNode;
    int n;

    do {
        barkNode = node->next;

        n = GetSortPosition(list_1, node->data);
        if (n) {
            // 插入节点
            ListInsertNode(list_1, n, node);
        }
        else {
            delete node;
        }

        node = barkNode;
    } while (node);
}

/*
 * ListIntersection 求两个列表的交集
 * 不重复数据(重复数据进行销毁)，复用内存空间
 * 完成后链表为 list_1, list_1 依旧有序
 */
void ListIntersection(LinkedList& list_1, LinkedList& list_2) {
    LinkedListNode* node = list_1.first;
    LinkedListNode* barkNode;

    int len = list_1.length;
    for (int i = 1; i <= len; i++) {
        // 判断是否存在，不存在则删除
        if (LocateELem(list_2, node->data) == NULL) {
            node = node->next;
            ListDelete(list_1, i);
            i--;
            len--;
        }
        else {
            node = node->next;
        }
    }
}

// GetMaxNode 获取值最大的节点
// 返回节点位置，搜索到的最大值节点返回到 maxNode
int GetMaxNode(LinkedList& list, LinkedListNode*& maxNode) {
    LinkedListNode* node = list.first;
    LinkedListNode* max = list.first;
    int maxPos = 1;

    for (int i = 1; i <= list.length; i++) {
        if (node->data > max->data) {
            max = node;
            maxPos = i;
        }
        node = node->next;
    }

    maxNode = max;
    return maxPos;
}