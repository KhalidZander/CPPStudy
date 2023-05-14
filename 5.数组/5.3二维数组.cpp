#include <iostream>
using namespace std;
int main()
{
#pragma region 数组定义
	int arr1[2][3];
	int arr2[3][4] = { {1,1,1,1}, {2,2,2,2,}, {3,3,3,3} };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << arr2[i][j] << " ";
		}
		cout << endl;
	}
#pragma endregion
#pragma region 数组名称作用
	//查看大小
	cout << "内存空间为：" << sizeof(arr2) << endl;
	cout << "第一行内存空间为：" << sizeof(arr2[0]) << endl;
	cout << "第一个内存空间为：" << sizeof(arr2[0][0]) << endl;
	//查看首地址(int用于进制转换 16 -> 10)
	cout << "查看首地址为：" << (int)arr2 << endl;
	cout << "查看首地址为：" << (int)&arr2[0][1] << endl;
#pragma endregion
#pragma region 应用
	int score[3][4] =
	{
		{100,100,100,0},
		{90 ,50 ,100,0},
		{60 ,70 ,80 ,0},
	};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			score[i][3] += score[i][j];
		}
		cout << "总分为：" << score[i][3] << endl;
	}
#pragma endregion



}
