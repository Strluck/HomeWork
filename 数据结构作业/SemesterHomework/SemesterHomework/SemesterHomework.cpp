#include <stdio.h>
#include "PolynomialOperation.h"

int main()
{
	int n;

	printf("输入多项式 a 的项长度:\n");
	scanf("%d", &n);
	printf("输入多项式 a 的各项系数(指数降序排列):\n");
	LinkedList poly_1 = PolynomialScanf(n);
	
	printf("输入多项式 b 的项长度:\n");
	scanf("%d", &n);
	printf("输入多项式 b 的各项系数(指数降序排列):\n");
	LinkedList poly_2 = PolynomialScanf(n);

	while (true) {
		printf("多项式 a 为: ");
		DebugPolynomialPrint(poly_1);
		printf("多项式 b 为: ");
		DebugPolynomialPrint(poly_2);

		printf("+--------------------+\n");
		printf("| 1.输出整数序列     |\n");
		printf("| 2.计算 a + b       |\n");
		printf("| 3.计算 a - b       |\n");
		printf("| 4.重新输入多项式 a |\n");
		printf("| 5.重新输入多项式 b |\n");
		printf("|                    |\n");
		printf("| 0.结束程序         |\n");
		printf("+--------------------+\n");

		printf("选择: ");
		scanf("%d", &n);
		switch(n) {
			case 0:
				return 0;

			case 1:
				printf("多项式 a 为: ");
				PolynomialPrint(poly_1);
				printf("多项式 b 为: ");
				PolynomialPrint(poly_2);
				break;

			case 2:
				LinkedList add = PolynomialAdd(poly_1, poly_2);
				printf("计算结果: a + b = ");
				DebugPolynomialPrint(add);
				break;

			case 3:
				LinkedList less = PolynomialLess(poly_1, poly_2);
				printf("计算结果: a - b = ");
				DebugPolynomialPrint(less);
				break;

			case 4:
				printf("输入多项式 a 的项长度:\n");
				scanf("%d", &n);
				printf("输入多项式 a 的各项系数(指数降序排列):\n");
				LinkedList poly_1 = PolynomialScanf(n);
				break;

			case 5:
				printf("输入多项式 b 的项长度:\n");
				scanf("%d", &n);
				printf("输入多项式 b 的各项系数(指数降序排列):\n");
				LinkedList poly_2 = PolynomialScanf(n);
				break;
		}
		printf("+--------------------+\n");
		printf("| 任意值退回菜单     |\n");
		printf("| 0.结束程序         |\n");
		printf("+--------------------+\n");

		printf("选择: ");
		scanf("%d", &n);
		if (n == 0) {
			return 0;
		}
	}
}
