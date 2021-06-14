#include "PolynomialOperation.h"
#include <stdio.h>

// 用于快速输入多项式
LinkedList PolynomialScanf(int n) {
	LinkedList poly = NewList();

	for (int i = 0; i < n; i++) {
		int ni;
		scanf("%d", &ni);
		ListInsertB(poly, ni); // 向链表末尾插入
	}

	return poly;
}

// 用于计算多项式的和
LinkedList PolynomialAdd(LinkedList& poly_1, LinkedList& poly_2) {
	LinkedListNode* polyNode_1 = poly_1.first; //第一个多项式链表首元节点
	LinkedListNode* polyNode_2 = poly_2.first; //第二个多项式链表首元节点
	LinkedList polyAdd = NewList();            //储存结果的多项式链

	/* 将项数较多的多项式不参加和运算的部分添加到结果polyAdd中 */
	int n = poly_1.length > poly_2.length ? 
		poly_1.length - poly_2.length : poly_2.length - poly_1.length;

	if (poly_1.length > poly_2.length) {
		printf("+");
		for (int i = 0; i < n; i++) {
			ListInsertB(polyAdd, polyNode_1->data);
			polyNode_1 = polyNode_1->next;
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			ListInsertB(polyAdd, polyNode_2->data);
			polyNode_2 = polyNode_2->next;
		}
	}

	/* 将两个多项式共有的指数的系数相加 */
	int min = poly_1.length < poly_2.length ? poly_1.length : poly_2.length;
	for (int i = 0; i < min; i++) {
		int add = polyNode_1->data + polyNode_2->data;
		ListInsertB(polyAdd, add);
		polyNode_1 = polyNode_1->next;
		polyNode_2 = polyNode_2->next;
	}

	return polyAdd;
}

// 用于计算多项式的差
LinkedList PolynomialLess(LinkedList& poly_1, LinkedList& poly_2) {
	LinkedListNode* polyNode_1 = poly_1.first; //第一个多项式链表首元节点
	LinkedListNode* polyNode_2 = poly_2.first; //第二个多项式链表首元节点
	LinkedList polyLess = NewList();           //储存结果的多项式链表

	/* 将项数较多的多项式不参加和运算的部分添加到结果polyLess中 */
	int n = poly_1.length > poly_2.length ?
		poly_1.length - poly_2.length : poly_2.length - poly_1.length;

	if (poly_1.length > poly_2.length) {
		for (int i = 0; i < n; i++) {
			ListInsertB(polyLess, polyNode_1->data);
			polyNode_1 = polyNode_1->next;
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			ListInsertB(polyLess, polyNode_2->data);
			polyNode_2 = polyNode_2->next;
		}
	}

	/* 将两个多项式共有的指数的系数相减 */
	int min = poly_1.length < poly_2.length ? poly_1.length : poly_2.length;
	for (int i = 0; i < min; i++) {
		int add = polyNode_1->data - polyNode_2->data;
		ListInsertB(polyLess, add);
		polyNode_1 = polyNode_1->next;
		polyNode_2 = polyNode_2->next;
	}

	return polyLess;
}

// 用于按照题目要求输出多项式
void PolynomialPrint(LinkedList& poly) {
	LinkedListNode* polyNode = poly.first; //多项式链表首元节点
	int i = poly.length - 1;
	printf("%d, ", poly.length);
	for (; i > 0; i--) {
		printf("%d, %d, ", polyNode->data, i);
		polyNode = polyNode->next;
	}
	printf("%d, %d\n", polyNode->data, i);
}

// 用于输出更直观的多项式
void DebugPolynomialPrint(LinkedList& poly) {
	LinkedListNode* polyNode = poly.first; //多项式链表首元节点
	int n = polyNode->data;
	int i = poly.length - 2;
	int x = i;
	
	for (; i > 0; i--) {
		n = polyNode->data;
		/* 输出多项式 */
		if (n > 1) {
			if (i == x) {
				printf("%dx^%d", n, i);
			}
			else {
				printf("+%dx^%d", n, i);
			}
			
		}
		else if (n < -1) {
			printf("%dx^%d", n, i);
		}
		else if (n == 1) {
			printf("+x^%d", i);
		}
		else if (n == -1) {
			printf("-x^%d", i);
		}
		polyNode = polyNode->next;
	}
	/* 输出多项式的一次项 */
	n = polyNode->data;
	if (n > 1) {
		printf("+%dx", n);
	}
	else if (n < -1) {
		printf("%dx", n);
	}
	else if (n == 1) {
		printf("x");
	}
	else if (n == -1) {
		printf("-x");
	}
	/* 输出多项式的常数项 */
	polyNode = polyNode->next;
	n = polyNode->data;
	if (n > 0) {
		printf("+%d\n", n);
	}
	else if (n < 0) {
		printf("%d\n", n);
	}
}