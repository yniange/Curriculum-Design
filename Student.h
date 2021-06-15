#pragma once

#include <string>

class Student
{
public:
	std::string ID = "";
	std::string name = "";
	std::string gender = "";
	float gMath = 0.0f;//数学成绩
	float gPhy = 0.0f;//物理成绩
	float gChem = 0.0f;//化学成绩

	void Show();
	float Average();//求平均成绩

	friend std::ofstream& operator<<(std::ofstream& ofs, const Student& stu);
	friend std::ifstream& operator>>(std::ifstream& ifs, Student& stu);
};

