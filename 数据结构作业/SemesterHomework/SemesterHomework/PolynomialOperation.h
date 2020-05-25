#include "LinkedList.h"

LinkedList PolynomialScanf(int n);                                // 用于快速输入多项式
LinkedList PolynomialAdd(LinkedList& poly_1, LinkedList& poly_2); // 用于计算多项式的和
LinkedList PolynomialLess(LinkedList& poly_1, LinkedList& poly_2);// 用于计算多项式的差
void PolynomialPrint(LinkedList& poly);                   // 用于按照题目要求输出多项式
void DebugPolynomialPrint(LinkedList& poly);              // 用于输出更直观的多项式
