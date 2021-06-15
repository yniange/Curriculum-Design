#include "App.h"
#include <iostream>
#include <fstream>
#include "Global.h"
#include <io.h>
#include <string>

App::~App()
{
	StuSet.clear();
}

char App::menu()
{
	char sel;
	while (true)
	{
		std::cout << "**添加学生信息---------------------A**\n";
		std::cout << "**删除指定学生信息-----------------R**\n";
		std::cout << "**输出所有学生信息-----------------S**\n";
		std::cout << "**查询一门课的平均成绩-------------V**\n";
		std::cout << "**查询一位同学的平均成绩-----------C**\n";
		std::cout << "**查询一门课的不及格人数-----------N**\n";
		std::cout << "**输出平均成绩最高的学生-----------H**\n";
		std::cout << "**输出平均成绩最低的学生-----------L**\n";
		std::cout << "**按平均成绩高低顺序输出学生信息---B**\n";
		std::cout << "**退出-----------------------------X**\n";
		std::cout << "**请选择操作：";
		std::cin >> sel;
		switch (sel)
		{
		case 'A':
		case 'a':
			return 'A';
		case 'R':
		case 'r':
			return 'R';
		case 'S':
		case 's':
			return 'S';
		case 'V':
		case 'v':
			return 'V';
		case 'C':
		case 'c':
			return 'C';
		case 'N':
		case 'n':
			return 'N';
		case 'H':
		case 'h':
			return 'H';
		case 'L':
		case 'l':
			return 'L';
		case 'B':
		case 'b':
			return 'B';
		case 'X':
		case 'x':
			return 'X';
		default:
			std::cout << "输入错误！请重新选择。\n";
		}
	}
}

//根据姓名查找，返回目标学生元素的下标，未找到，返回-1
int App::FindStu(std::string name)
{
	if (StuSet.empty())
		return -1;

	int len = static_cast<int>(StuSet.size());
	for (int i = 0; i < len; ++i)
	{
		if (name == StuSet[i].name)
		{//找到该学生，将下标返回
			return i;
		}

	}
	return -1;//未找到该学生
}

bool App::AddStu(bool bEndAdd)
{
	if (bEndAdd)
	{
		std::cout << "请输入第 " << StuSet.size() + 1 << " 位学生的信息\n";
		Student stu;
		InputStu(stu);
		StuSet.push_back(stu);
		std::cout << "添加成功！\n\n";
		return true;
	}
	else
	{
		std::cout << "在哪位同学之前/后插入一位同学的信息？\n请输入姓名：";
		std::string name;
		getchar();
		getline(std::cin, name);
		int iTar = FindStu(name);//查找
		if (-1 == iTar)
		{
			std::cout << "未找到目标同学，插入操作失败！\n\n";
			return false;
		}
		else
		{
			char c;
			while (true)
			{
				std::cout << "在 " << name
					<< " 之前还是之后插入新同学信息？“前”请输入“B”，否则输入“A”\n";
				std::cin >> c;
				if ('b' == c || 'B' == c || 'a' == c || 'A' == c)
				{
					break;
				}
				else
				{
					std::cout << "输入错误！请重新选择操作。\n";
				}
			}
			std::cout << "请输入第 " << StuSet.size() + 1 << " 位学生的信息\n";
			Student stu;
			InputStu(stu);
			switch (c)
			{
			case 'B':
			case 'b':
			{//之前插入
				StuSet.insert(StuSet.begin() + iTar, stu);
				break;
			}
			case 'A':
			case 'a':
			{//之后插入
				StuSet.insert(StuSet.begin() + iTar + 1, stu);
				//break;
			}
			}
			std::cout << "插入成功！\n\n";
			return true;
		}
	}
}

//删除一个学生
bool App::RemoveStu()
{
	if (StuSet.empty())
	{
		std::cout << "无数据，删除操作失败！\n\n";
		return false;
	}

	std::cout << "请输入待删除同学的姓名：";
	std::string name;
	getchar();
	getline(std::cin, name);
	int iTar = FindStu(name);
	if (-1 == iTar)
	{
		std::cout << "未找到该学生信息，删除操作失败！\n\n";
		return false;
	}

	StuSet.erase(StuSet.begin() + iTar);

	std::cout << name << "被成功删除！\n\n";
	return true;
}

//输出
void App::ShowStu()
{
	if (StuSet.empty())
	{
		std::cout << "目前无学生数据\n";
		return;
	}

	for (auto& stu : StuSet)
	{
		stu.Show();
	}
	std::cout << std::endl;
}

float App::CourseAverage()
{
	if (StuSet.empty())
	{
		std::cout << "没有学生信息，本次操作取消！\n";
		return 0.0f;
	}

	std::cout << "查询哪门课程的平均成绩？\n";
	char sel;
	while (true)
	{
		std::cout << "数学————1\n";
		std::cout << "物理————2\n";
		std::cout << "化学————3\n";
		std::cout << "请选择：";
		std::cin >> sel;
		if ('1' == sel || '2' == sel || '3' == sel)
			break;
		else
			std::cout << "输入错误，请重新选择。\n";
	}
	float aver = 0.0f;
	switch (sel)
	{
	case '1':
	{
		for (auto t : StuSet)
		{
			aver += t.gMath;
		}
		aver /= StuSet.size();
		std::cout << "数学平均成绩为：" << aver << std::endl;
		break;
	}
	case '2':
	{
		for (auto t : StuSet)
		{
			aver += t.gPhy;
		}
		aver /= StuSet.size();
		std::cout << "物理平均成绩为：" << aver << std::endl;
		break;
	}
	case '3':
	{
		for (auto t : StuSet)
		{
			aver += t.gChem;
		}
		aver /= StuSet.size();
		std::cout << "化学平均成绩为：" << aver << std::endl;
		break;
	}
	}
	std::cout << std::endl;
	return aver;
}

int App::FailedCount()
{
	if (StuSet.empty())
	{
		std::cout << "没有学生信息，本次操作取消！\n";
		return 0;
	}

	std::cout << "查询哪门课程的不及格人数？\n";
	char sel;
	while (true)
	{
		std::cout << "数学————1\n";
		std::cout << "物理————2\n";
		std::cout << "化学————3\n";
		std::cout << "请选择：";
		std::cin >> sel;
		if ('1' == sel || '2' == sel || '3' == sel)
			break;
		else
			std::cout << "输入错误，请重新选择。\n";
	}
	int fcount = 0;
	switch (sel)
	{
	case '1':
	{
		for (auto t : StuSet)
		{
			if (t.gMath < 60)
				fcount++;
		}
		std::cout << "数学不及格人数为：" << fcount << std::endl;
		break;
	}
	case '2':
	{
		for (auto t : StuSet)
		{
			if (t.gPhy < 60)
				fcount++;
		}
		std::cout << "物理不及格人数为：" << fcount << std::endl;
		break;
	}
	case '3':
	{
		for (auto t : StuSet)
		{
			if (t.gChem < 60)
				fcount++;
		}
		std::cout << "化学不及格人数为：" << fcount << std::endl;
		break;
	}
	}

	std::cout << std::endl;
	return fcount;
}

void App::HighestAverage()
{
	if (StuSet.empty())
	{
		std::cout << "没有学生信息，本次操作取消！\n";
		return;
	}

	float amax = 0.0f;
	int totalCount = static_cast<int>(StuSet.size());
	int indexmax = 0;
	float aver;
	for (int i = 0; i < totalCount; ++i)
	{
		aver = StuSet[i].Average();
		if (amax < aver)
		{
			amax = aver;
			indexmax = i;
		}
	}
	std::cout << StuSet[indexmax].name << " 的平均成绩最高，数学：" << StuSet[indexmax].gMath
		<< " ，物理：" << StuSet[indexmax].gPhy << " ，化学：" << StuSet[indexmax].gChem
		<< " ，平均成绩：" << StuSet[indexmax].Average() << std::endl << std::endl;
}

void App::LowestAverage()
{
	if (StuSet.empty())
	{
		std::cout << "没有学生信息，本次操作取消！\n";
		return;
	}

	float amim = StuSet[0].Average();
	int totalCount = static_cast<int>(StuSet.size());
	int indexmin = 0;
	float aver;
	for (int i = 1; i < totalCount; ++i)
	{
		aver = StuSet[i].Average();
		if (amim > aver)
		{
			amim = aver;
			indexmin = i;
		}
	}
	std::cout << StuSet[indexmin].name << " 的平均成绩最低，数学：" << StuSet[indexmin].gMath
		<< " ，物理：" << StuSet[indexmin].gPhy << " ，化学：" << StuSet[indexmin].gChem
		<< " ，平均成绩：" << StuSet[indexmin].Average() << std::endl << std::endl;
}

void App::ShowByAver()
{
	if (StuSet.empty())
	{
		std::cout << "没有学生信息，本次操作取消！\n";
		return;
	}

	std::vector<Student> sortstu;
	for (auto& t: StuSet)
	{
		sortstu.push_back(t);
	}

	size_t s = sortstu.size();
	Student stu;
	for (size_t i = 0; i < s - 1; ++i)
	{
		for (size_t j = i + 1; j < s; ++j)
		{
			if (sortstu[i].Average() < sortstu[j].Average())
			{
				stu=sortstu[i];
				sortstu[i] = sortstu[j];
				sortstu[j] = stu;
			}
		}
	}
	for (auto& t : sortstu)
	{
		t.Show();
	}
	std::cout << std::endl;
}

bool App::WriteFile()
{
	std::ofstream oFile(FileName, std::ios_base::out);

	//文件开头一行说明性文字
	std::string strTmp = "学生信息管理系统\n";
	oFile << strTmp;
	strTmp = std::to_string(StuSet.size()) + "\n";
	oFile << strTmp;

	for (auto& stu : StuSet)
	{
		oFile << stu;
	}

	oFile.close();
	return true;
}

bool App::ReadFile()
{
	//清空容器
	StuSet.clear();
	//判断文件stu_data.txt是否已存在
	//_access_s判断数据文件是否存在
	if (0 != _access_s(FileName.c_str(), 0))
	{
		return false;
	}

	//读文件中学生数据至容器
	char aLine[LineMaxLen]{ "" };
	std::ifstream iFile(FileName);

	iFile.getline(aLine, sizeof(aLine));//文件第一行，无效文字行

	iFile.getline(aLine, sizeof(aLine));//文件第二行，一个整数，代表学生个数
	std::string str(aLine);
	int iCount = stoi(str);//学生个数
	Student stu;
	for (int i = 0; i < iCount; ++i)
	{
		iFile >> stu;
		StuSet.push_back(stu);
	}

	iFile.close();
	return true;
}

Student& App::InputStu(Student& stu)
{
	std::cout << "学号：";
	std::cin >> stu.ID;
	std::cout << "姓名：";
	getchar();
	getline(std::cin, stu.name);
	std::cout << "性别：";
	std::cin >> stu.gender;
	std::cout << "数学成绩：";
	std::cin >> stu.gMath;
	std::cout << "物理成绩：";
	std::cin >> stu.gPhy;
	std::cout << "化学成绩：";
	std::cin >> stu.gChem;

	return stu;
}

//系统如果是第一次运行，用如下数据做为系统的初始数据
void App::InitSet()
{
	StuSet.clear();
	Student stu;
	std::string strid[]{ "001","002", "003", "004", "005", "006" };
	std::string strname[]{ "张三","李四","王五","陈六","赵七","钱八" };
	std::string strgen[]{ "男","女","男","女","男","女" };
	float gm[]{ 87,68,77,100,55,78 };
	float gp[]{ 79,87,64,100,68,62 };
	float gc[]{ 90,69,71,100,64,52 };
	for (int i = 0; i < 6; ++i)
	{
		stu.ID = strid[i];
		stu.name = strname[i];
		stu.gender = strgen[i];
		stu.gMath = gm[i];
		stu.gPhy = gp[i];
		stu.gChem = gc[i];
		StuSet.push_back(stu);
	}
}

float App::StuAverage()
{
	if (StuSet.empty())
	{
		std::cout << "没有学生信息，本次操作取消！\n";
		return 0.0f;
	}

	std::cout << "查询哪位同学的平均成绩？\n";
	std::string na;
	int stuIndex;
	while (true)
	{
		std::cin >> na;
		if ("X" == na || "x" == na)
		{
			std::cout << "操作取消！\n\n";
			return 0.0f;
		}
		stuIndex = FindStu(na);
		if (-1 != stuIndex)
			break;
		else
			std::cout << "没有 " << na << " 这位同学，放弃查询请按x键后回车，继续请重新输入学生姓名：\n";
	}

	float aver = StuSet[stuIndex].Average();
	std::cout << na << " 的平均成绩为：" << aver << std::endl << std::endl;
	return aver;
}
