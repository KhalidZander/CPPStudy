#include <iostream>
#include <string>
using namespace std;
#define MAX 1000

struct Person
{
	// 姓名
	string m_Name;
	// 性别 0 男 1 女
	int m_Sex;
	// 年龄
	int m_Age;
	// 电话
	string m_Phone;
	// 地址
	string m_Addres;
};

struct Addressbooks
{
	Person personList[MAX];

	int m_Size;
};

// 打印主菜单
void ShowMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1.添加联系人   *****" << endl;
	cout << "*****  2.显示联系人   *****" << endl;
	cout << "*****  3.删除联系人   *****" << endl;
	cout << "*****  4.查找联系人   *****" << endl;
	cout << "*****  5.修改联系人   *****" << endl;
	cout << "*****  6.清空联系人   *****" << endl;
	cout << "*****  0.退出联系人   *****" << endl;
	cout << "***************************" << endl;
}
// 添加联系人
void AddPerson(Addressbooks* abs)
{
	if (abs->m_Size >= MAX)
	{
		cout << "通讯录已满，无法添加联系人!";
		return;
	}
	else
	{
		//添加联系人
		// name
		cout << "Please Input Name:" << endl;
		cin >> abs->personList[abs->m_Size].m_Name;
		// sex
		cout << "Please Input Sex:" << endl;
		cout << "0 -- Boy:" << endl;
		cout << "1 -- Gril:" << endl;
		int sex = -1;
		while (true)
		{
			cin >> sex;
			if (sex == 0 || sex == 1)
			{
				abs->personList[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "Error Sex Vale" << endl;
		}
		// age
		cout << "Please Input Age:" << endl;
		cin >> abs->personList[abs->m_Size].m_Age;
		// phone
		cout << "Please Input Phone:" << endl;
		cin >> abs->personList[abs->m_Size].m_Phone;
		// addres
		cout << "Please Input Addres:" << endl;
		cin >> abs->personList[abs->m_Size].m_Addres;

		cout << "Add Person Successful!" << endl;

		abs->m_Size++;

		system("pause");
		system("cls");
	}

}
// 显示联系人
void ShowAllPerson(const Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "通讯录中联系人为零，没有可显示记录!";
		return;
	}
	else
	{
		cout << "姓名\t性别\t年龄\t电话\t\t地址" << endl;
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << abs->personList[i].m_Name << "\t"
				<< (abs->personList[i].m_Sex == 1 ? "男" : "女") << "\t"
				<< abs->personList[i].m_Age << "\t"
				<< abs->personList[i].m_Phone << "\t\t"
				<< abs->personList[i].m_Addres << endl;
		}
		system("pause");
		system("cls");
	}
}
// 检测联系人
int DetectedPerson(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personList[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}
// 删除联系人
void DeletePerson(Addressbooks* abs)
{
	cout << "Please Input Need Delete Person Name" << endl;
	string name;
	cin >> name;
	int index = DetectedPerson(abs, name);
	if (index >= 0 && index < MAX)
	{
		abs->personList[index] = abs->personList[abs->m_Size - 1];
		abs->personList[abs->m_Size - 1] = abs->personList[abs->m_Size];
		abs->m_Size--;
		cout << "Delete Successful!" << endl;
	}
	else
	{
		cout << "System Can't Find this Name" << endl;
	}
	system("pause");
	system("cls");
}
// 查找联系人
void FindPerson(Addressbooks* abs)
{
	cout << "Please Input Need Find Person Name" << endl;
	string name;
	cin >> name;
	int index = DetectedPerson(abs, name);
	if (index >= 0 && index < MAX)
	{
		cout << "Find Successful!" << endl;
		cout << "姓名\t性别\t年龄\t电话\t\t地址" << endl;
		cout << abs->personList[index].m_Name << "\t"
			<< (abs->personList[index].m_Sex == 1 ? "男" : "女") << "\t"
			<<  abs->personList[index].m_Age << "\t"
			<<  abs->personList[index].m_Phone << "\t\t"
			<<  abs->personList[index].m_Addres << endl;
	}
	else
	{
		cout << "System Can't Find this Name" << endl;
	}
	system("pause");
	system("cls");
}
// 修改联系人
void ModifyPerson(Addressbooks* abs)
{
	cout << "Please Input Need Find Person Name" << endl;
	string name;
	cin >> name;
	int index = DetectedPerson(abs, name);
	if (index >= 0 && index < MAX)
	{
		// name
		cout << "Please Input Name:" << endl;
		cin >> abs->personList[index].m_Name;
		// sex
		cout << "Please Input Sex:" << endl;
		cout << "0 -- Boy:" << endl;
		cout << "1 -- Gril:" << endl;
		int sex = -1;
		while (true)
		{
			cin >> sex;
			if (sex == 0 || sex == 1)
			{
				abs->personList[index].m_Sex = sex;
				break;
			}
			cout << "Error Sex Vale" << endl;
		}
		// age
		cout << "Please Input Age:" << endl;
		cin >> abs->personList[index].m_Age;
		// phone
		cout << "Please Input Phone:" << endl;
		cin >> abs->personList[index].m_Phone;
		// addres
		cout << "Please Input Addres:" << endl;
		cin >> abs->personList[index].m_Addres;

		cout << "Modify Person Successful!" << endl;
	}
	else
	{
		cout << "System Can't Find this Name" << endl;
	}
	system("pause");
	system("cls");
}
// 清空联系人
void ClearAddPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	
	cout << "Clear Add Person Successful!" << endl;

	system("pause");
	system("cls");
}
int main()
{
	Addressbooks abs;
	abs.m_Size = 0;

	// 用户输入变量
	int select = 0;

	while (true)
	{
		ShowMenu();

		cin >> select;

		switch (select)
		{
			//1.添加联系人
			//2.显示联系人
			//3.删除联系人
			//4.查找联系人
			//5.修改联系人
			//6.清空联系人
			//0.退出联系人
		case 1:
			AddPerson(&abs);
			break;
		case 2:
			ShowAllPerson(&abs);
			break;
		case 3:
			DeletePerson(&abs);
			break;
		case 4:
			FindPerson(&abs);
			break;
		case 5:
			ModifyPerson(&abs);
			break;
		case 6:
			ClearAddPerson(&abs);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			system("pause");
			system("cls");
			break;
		}
	}
}
