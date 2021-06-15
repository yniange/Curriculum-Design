#pragma once

#include "Student.h"
#include <vector>

class App
{
public:
	App() = default;
	~App();

	char menu();//主菜单
	//在容器中中根据姓名查找学生
	int FindStu(std::string name);

	//往容器中添加一个元素，bEndAdd为true表示在末尾添加
	bool AddStu(bool bEndAdd = true);
	bool RemoveStu();//从容器中删除一个元素
	void ShowStu();//显示容器中所有学生信息
	float CourseAverage();//输出一门课的平均成绩
	int FailedCount();//某门课不及格人数
	void HighestAverage();//平均成绩最高的学生
	void LowestAverage();//平均成绩最低的学生
	void ShowByAver();//由大到小按平均成绩输出信息

	bool WriteFile();
	bool ReadFile();
	Student& InputStu(Student& stu);
private:
	std::vector<Student> StuSet;
public:
	void InitSet();
	float StuAverage();
};

