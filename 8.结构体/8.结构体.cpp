#include <iostream>
#include <string>
using namespace std;

struct Student
{
	//成员列表
	string name = "Unname";
	int age = 0;
	int score = 0;
};
struct  Teacher
{
	int id;
};
struct Person
{
	int age;
	string name;
	Teacher teacher;
};

struct Student8
{
	string studentName;
	int score;
};

struct Teacher8
{
	string teacherName;
	Student8 students[5];
};

struct Hero
{
	string HeroName;
	int Age;
	string Sex;
};

void PrintStudentInfo(Student s)
{
	s.name = "名字：" + s.name;
	s.age -= 1;
	s.score += 1;
	cout << "数值传递：" << s.name << " " << s.age << " " << s.score << endl;
}

void PrintStudentInfo(Student* s)
{
	s->name = "名字：" + s->name;
	s->age -= 1;
	s->score += 1;
	cout << "地址传递：" << s->name << " " << s->age << " " << s->score << endl;
}

void PrintStudentInfoNormal(Student s)
{
	cout << s.name << " " << s.age << " " << s.score << endl;
}

/// <summary>
/// 使用形参会重新复制一份结构体的数据，浪费内存空间
/// </summary>
/// <param name="t"></param>
void PrintTeacherInfo(Teacher t)
{

}

/// <summary>
/// 使用地址可以减少内存小号，同时使用const避免修改数值，只能读不能写数据。
/// </summary>
/// <param name="t"></param>
void PrintTeacherInfo(const Teacher* t)
{
	//此时不能修改t指向的值
	//t->id = 10;//不合法
	cout << t->id << endl;
}

void SetAllInfo(Teacher8* t, int len1, int len2)
{
	string nameSeed = "ABCDEFGHIJKLMNOPKRSTUVWXYZ";
	for (int i = 0; i < len1; i++)
	{
		t[i].teacherName = "Teacher_";
		t[i].teacherName += nameSeed[i];
		for (int j = 0; j < len2; j++)
		{
			t[i].students[j].studentName = "Student_";
			t[i].students[j].studentName += nameSeed[j];
			t[i].students[j].score = j * 10;
		}
	}
}

void PrintAllInfo(const Teacher8* t, int len1, int len2)
{
	for (int i = 0; i < len1; i++)
	{
		cout << "老师：" << (t + i)->teacherName << endl;
		for (int j = 0; j < len2; j++)
		{
			cout << "学生名字：" << (t + i)->students[j].studentName << endl;
			cout << "学生分数：" << (t + i)->students[j].score << endl;
		}
	}
}

void HeroBubbleSorting(Hero* hero, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if ((hero + j)->Age > (hero + j + 1)->Age)
			{
				Hero tmp = *(hero + j);
				*(hero + j) = *(hero + j + 1);
				*(hero + j + 1) = tmp;
			}
		}
	}
}

//创建方式
//2.1 struct Student s1;
//2.2 struct Student s2 = { ... }
//2.3 定义结构体时创建变量
int main()
{
	//2.1
	cout << "--------------------2.结构体声明--------------------" << endl;
	Student s1;
	s1.name = "刘定林";
	s1.age = 21;
	s1.score = 59;
	cout << s1.name << s1.age << s1.score << endl;
	//2.2
	Student s2 = { "郑凯",22,98 };
	cout << s2.name << s2.age << s2.score << endl;
	//2.3
	struct Student s3;
	cout << s3.name << s3.age << s3.score << endl;

	//3.结构体数组
	cout << "--------------------3.结构体数组--------------------" << endl;
	Student arr[3] = { s1,s2,s3 };
	struct Student arr2[2] = { {"1",1,1},{"2",2,2} };

	//4.结构体指针
	cout << "--------------------4.结构体指针--------------------" << endl;
	Student student4 = { "啊四",14,44 };
	//指针指向结构体变量
	Student* p4 = &student4;
	//通过指针访问结构体变量内的数据
	cout << "p4的地址" << p4 << endl;
	cout << "指针操作p4的年龄" << p4->age << endl;
	p4->age = 100;
	cout << "指针操作p4的年龄" << p4->age << endl;

	//5.结构体嵌套
	cout << "--------------------5.结构体嵌套--------------------" << endl;
	Person person5 = { 20,"图",{10001} };
	Person* p5 = &person5;
	cout << p5->teacher.id << endl;

	//6.结构体作函数参数
	cout << "--------------------6.结构体作函数参数--------------------" << endl;
	Student s6 = { "老六",16,66 };
	cout << "初始值：";
	PrintStudentInfoNormal(s6);
	PrintStudentInfo(s6);
	PrintStudentInfo(&s6);
	cout << "修改后：";
	PrintStudentInfoNormal(s6);

	//7.结构体中const使用场景
	cout << "--------------------7.结构体中const使用场景--------------------" << endl;
	Teacher s7 = { 996 };
	PrintTeacherInfo(&s7);

	//8.1案例
	cout << "-----------------------------8.案例-----------------------------" << endl;
	cout << "-----------------------------8.1打印学生成绩-----------------------------" << endl;
	Teacher8 teachers[3];
	int len1 = sizeof(teachers) / sizeof(Teacher8);
	int len2 = sizeof(teachers[0].students) / sizeof(Student8);

	SetAllInfo(&teachers[0], len1, len2);

	PrintAllInfo(&teachers[0], len1, len2);
	cout << "-----------------------------8.2冒泡排序-----------------------------" << endl;
	Hero heros[5] =
	{
		{ "一号英雄",14,"男" },
		{ "二号英雄",16,"男" },
		{ "三号英雄",11,"女" },
		{ "四号英雄",16,"男" },
		{ "五号英雄",22,"女" },
	};

	int len82 = sizeof(heros) / sizeof(heros[0]);

	HeroBubbleSorting(&heros[0], len82);

	cout << "Name\t\tAge\tSex" << endl;
	for (int i = 0; i < len82; i++)
	{
		cout << heros[i].HeroName << "\t" << heros[i].Age << "\t" << heros[i].Sex << endl;
	}

	system("pause");

	return 0;
}

