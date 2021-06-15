#include <iostream>
#include "Student.h"
#include "App.h"
#include <io.h>
#include "Global.h"

App theApp;

int main(void)
{
	std::cout << "****** 欢迎来到学生信息管理系统 ******" << std::endl;
	//如果是第一次运行系统（通过探测数据文件是否存在），设置初始数据。

	//判断文件stu_data.txt是否已存在
	//_access_s判断数据文件是否存在
	if (0 != _access_s(FileName.c_str(), 0))
	{//如果数据文件不存在，利用初始数据设置StuSet
		theApp.InitSet();
	}
	else
	{//如果数据文件存在，则从数据文件中读取存储在文件中的学生数据
		theApp.ReadFile();
	}

	while (true)
	{
		switch (theApp.menu())
		{
		case 'A':
		{//插入
			theApp.AddStu(false);
			break;
		}
		case 'R':
		{//删除
			theApp.RemoveStu();
			break;
		}
		case 'S':
		{//输出
			theApp.ShowStu();
			break;
		}
		case 'V':
		{
			//一门课的平均成绩
			theApp.CourseAverage();
			break;
		}
		case 'C':
		{
			//一位同学的平均成绩
			theApp.StuAverage();
			break;
		}
		case 'N':
		{
			//一门课的不及格人数
			theApp.FailedCount();
			break;
		}
		case 'H':
		{
			//平均成绩最高的学生
			theApp.HighestAverage();
			break;
		}
		case 'L':
		{
			//平均成绩最低的学生
			theApp.LowestAverage();
			break;
		}
		case 'B':
		{
			theApp.ShowByAver();
			break;
		}
		case 'X':
		{//退出
			theApp.WriteFile();	//程序结束前，将当前的学生信息存储至数据文件中
			std::cout << "系统退出，再见！" << std::endl;
			return 0;
		}
		}
	}
}