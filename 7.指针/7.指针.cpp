#include <iostream>
using namespace std;
void Swap01(int p1, int p2)
{
	int temp = p1;
	p1 = p2;
	p2 = temp;
}

/// <summary>
/// 交换p1和p2的地址中的数值，
/// 只修改了*p1和*p2，并没有修改p1和p2的具体值，即没修修改地址，只修改数值
/// </summary>
/// <param name="p1">地址1</param>
/// <param name="p2">地址2</param>
void Swap02(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

/// <summary>
/// 冒泡排序
/// </summary>
/// <param name="arr">数组首地址</param>
/// <param name="len">数组长度</param>
void BubbleSort(int* arr, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (*(arr + j) > *(arr + j + 1))
			{
				Swap02(arr + j, arr + j + 1);
			}
		}
	}
}

/// <summary>
/// 打印数组
/// </summary>
/// <param name="arr">数组首地址</param>
/// <param name="len">数组长度</param>
void PrintArray(int* arr, int len)
{
	cout << "开始打印" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << *(arr + i) << " ";
	}
	cout << endl << "打印结束" << endl;
}
int main()
{
	//1.定义指针
	int a = 10;
	int* p;
	p = &a;
	cout << &a << endl;
	cout << p << endl;

	//2.使用指针
	cout << "解指针:" << *p << endl;
	*p = 1000;
	cout << *p << endl;
	cout << a << endl;
	//3.内存大小
	cout << "指针内存大小:" << sizeof(p) << endl;

	//4.1空指针
	//初始化
	int* p4 = NULL;
	//cout<<"4.1 初始化指针：" << *p4 << endl;
	//不可访问
	//0~255的内存编号不可访问
	//*p = 100;
	//cout << *p << endl;
	//4.2野指针
	//没有申请直接访问会报错
	/*p = (int*)0x1100;*/


	//5.const
	int a5 = 10;
	int b5 = 10;
	const int* p5 = &a5;

	//5.1常量指针
	p5 = &b5;//合法
	//*p5 = 20;//不合法
	//5.2指针常量
	int* const p52 = &a5;
	*p52 = 20; //合法
	//p52  = &b5;//不合法
	//5.3
	const int* const p53 = &a5;
	//*p53 = 20; //不合法
	//p53  = &b5;//不合法

	//6.指针和数组
	cout << "----------------------6.指针和数组------------------------" << endl;
	int arr[10] = { 11,22,33,44,55,66,77,88,99,110 };
	int* p6 = arr;
	for (int i = 0; i < 10; i++)
	{
		cout << "第" << i + 1 << "个元素，地址为：" << (int)p6 << "，数值为：" << *p6 << endl;
		p6++; //对于指针来说，++就是代码指向下一个内存块
	}
	cout << "循环后" << (int)p6 << endl;

	//7.指针和函数
	cout << "----------------------7.指针和函数------------------------" << endl;
	//地址传递
	int a7 = 10;
	int b7 = 20;
	cout << "a:" << a7 << "b:" << b7 << endl;
	Swap02(&a7, &b7);
	cout << "a:" << a7 << "b:" << b7 << endl;

	//8.指针、函数、数组
	cout << "----------------------8.指针、函数、数组------------------" << endl;
	// 新建数组
	int arr8[10] = { 4,3,6,9,1,2,10,8,7,5 };

	// 设置数组长度
	int len = sizeof(arr8) / sizeof(arr8[0]);

	PrintArray(&arr8[0], len);

	BubbleSort(&arr8[0], len);

	PrintArray(&arr8[0], len);
}

