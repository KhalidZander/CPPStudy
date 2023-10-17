#include <iostream>
#include <string>
using namespace std;

void Swap3(int& a, int& b)
{
	int tmp = b;
	b = a;
	a = tmp;
}

int& Test41()
{
	int a = 10;
	return a;
}

int& Test42()
{
	static int a = 10;
	return a;
}

void Print6(const int& a)
{
	// 不合法
	// a = 10;
	cout << a << endl;
}


int main()
{
	cout << "--------------------2.1 引用的基本使用--------------------" << endl;
	int a1 = 10;
	int& b1 = a1;
	cout << "更改前a:" << a1 << endl;
	cout << "更改前b:" << b1 << endl;
	b1 = 100;
	cout << "更改后a:" << a1 << endl;
	cout << "更改后b:" << b1 << endl;
	cout << "--------------------2.2 引用的注意事项--------------------" << endl;
	int a2 = 10;
	int c2 = 100;
	// 必须初始化
	int& b2 = a2;
	// 初始化后改变会报错
	// int& b2 = c2;
	cout << "--------------------2.3 引用做函数参数--------------------" << endl;
	int a3 = 10;
	int b3 = 20;
	cout << "Swap前a:" << a3 << endl;
	cout << "Swap前b:" << b3 << endl;
	Swap3(a3, b3);
	cout << "Swap后a:" << a3 << endl;
	cout << "Swap后b:" << b3 << endl;

	cout << "--------------------2.4 引用做函数返回值--------------------" << endl;
	int& a4 = Test41();
	cout << a4 << endl;

	int& b4 = Test42();
	cout << b4 << endl;
	Test42() = 1000;
	cout << b4 << endl;

	cout << "--------------------2.5 引用的本质--------------------" << endl;
	cout << "--------------------2.6 常量引用--------------------" << endl;

	//合法
	const int& a6 = 10;
	int b6 = 20;
	Print6(b6);
	cout << b6 << endl;
}

