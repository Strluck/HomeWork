#include "PolynomialOperation.h"
#include <stdio.h>

// ���ڿ����������ʽ
LinkedList PolynomialScanf(int n) {
	LinkedList poly = NewList();

	for (int i = 0; i < n; i++) {
		int ni;
		scanf("%d", &ni);
		ListInsertB(poly, ni); // ������ĩβ����
	}

	return poly;
}

// ���ڼ������ʽ�ĺ�
LinkedList PolynomialAdd(LinkedList& poly_1, LinkedList& poly_2) {
	LinkedListNode* polyNode_1 = poly_1.first; //��һ������ʽ������Ԫ�ڵ�
	LinkedListNode* polyNode_2 = poly_2.first; //�ڶ�������ʽ������Ԫ�ڵ�
	LinkedList polyAdd = NewList();            //�������Ķ���ʽ��

	/* �������϶�Ķ���ʽ���μӺ�����Ĳ�����ӵ����polyAdd�� */
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

	/* ����������ʽ���е�ָ����ϵ����� */
	int min = poly_1.length < poly_2.length ? poly_1.length : poly_2.length;
	for (int i = 0; i < min; i++) {
		int add = polyNode_1->data + polyNode_2->data;
		ListInsertB(polyAdd, add);
		polyNode_1 = polyNode_1->next;
		polyNode_2 = polyNode_2->next;
	}

	return polyAdd;
}

// ���ڼ������ʽ�Ĳ�
LinkedList PolynomialLess(LinkedList& poly_1, LinkedList& poly_2) {
	LinkedListNode* polyNode_1 = poly_1.first; //��һ������ʽ������Ԫ�ڵ�
	LinkedListNode* polyNode_2 = poly_2.first; //�ڶ�������ʽ������Ԫ�ڵ�
	LinkedList polyLess = NewList();           //�������Ķ���ʽ����

	/* �������϶�Ķ���ʽ���μӺ�����Ĳ�����ӵ����polyLess�� */
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

	/* ����������ʽ���е�ָ����ϵ����� */
	int min = poly_1.length < poly_2.length ? poly_1.length : poly_2.length;
	for (int i = 0; i < min; i++) {
		int add = polyNode_1->data - polyNode_2->data;
		ListInsertB(polyLess, add);
		polyNode_1 = polyNode_1->next;
		polyNode_2 = polyNode_2->next;
	}

	return polyLess;
}

// ���ڰ�����ĿҪ���������ʽ
void PolynomialPrint(LinkedList& poly) {
	LinkedListNode* polyNode = poly.first; //����ʽ������Ԫ�ڵ�
	int i = poly.length - 1;
	printf("%d, ", poly.length);
	for (; i > 0; i--) {
		printf("%d, %d, ", polyNode->data, i);
		polyNode = polyNode->next;
	}
	printf("%d, %d\n", polyNode->data, i);
}

// ���������ֱ�۵Ķ���ʽ
void DebugPolynomialPrint(LinkedList& poly) {
	LinkedListNode* polyNode = poly.first; //����ʽ������Ԫ�ڵ�
	int n = polyNode->data;
	int i = poly.length - 2;
	int x = i;
	
	for (; i > 0; i--) {
		n = polyNode->data;
		/* �������ʽ */
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
	/* �������ʽ��һ���� */
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
	/* �������ʽ�ĳ����� */
	polyNode = polyNode->next;
	n = polyNode->data;
	if (n > 0) {
		printf("+%d\n", n);
	}
	else if (n < 0) {
		printf("%d\n", n);
	}
}