#include "LinkedList.h"

LinkedList PolynomialScanf(int n);                                // ���ڿ����������ʽ
LinkedList PolynomialAdd(LinkedList& poly_1, LinkedList& poly_2); // ���ڼ������ʽ�ĺ�
LinkedList PolynomialLess(LinkedList& poly_1, LinkedList& poly_2);// ���ڼ������ʽ�Ĳ�
void PolynomialPrint(LinkedList& poly);                   // ���ڰ�����ĿҪ���������ʽ
void DebugPolynomialPrint(LinkedList& poly);              // ���������ֱ�۵Ķ���ʽ
