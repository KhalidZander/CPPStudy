#include <iostream>
#include"swap.h";
using namespace std;
// 写在main方法之前
int Add(int num1, int num2)
{
	return num1 + num2;
}
void Swap(int a, int b)
{
	cout << "a:" << a << " b:" << b << endl;
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	cout << "a:" << a << " b:" << b << endl;
}

////函数声明
//int Max(int a, int b);
int main()
{
	cout << Add(1, 2) << endl;
	int a = 123,  b = 456;
	cout << "传值前" << "a:" << a << " b:" << b << endl;
	Swap(a, b);
	cout << "传值后" << "a:" << a << " b:" << b << endl;

	cout << "最大值" << Max(10, 20) << endl;
}
//int Max(int a, int b)
//{
//	return a > b ? a : b;
//}