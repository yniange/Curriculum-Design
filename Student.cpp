#include "Student.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "Global.h"
#include <iomanip>

void Student::Show()
{
	std::cout << "学号：" << std::setw(3) << ID
		<< "\t姓名：" << std::setw(10) << std::setiosflags(std::ios::left) << name
		<< "\t性别：" << gender
		<< "\t数学：" << gMath
		<< "\t物理：" << gPhy
		<< "\t化学：" << gChem
		<< std::endl;
}

float Student::Average()
{
	return (gMath + gPhy + gChem) / 3.0f;
}

//重载<<运算符
std::ofstream& operator<<(std::ofstream& ofs, const Student& stu)
{
	ofs << stu.ID;
	ofs << ',';
	ofs << stu.name;
	ofs << ',';
	ofs << stu.gender;
	ofs << ',';
	ofs << stu.gMath;
	ofs << ',';
	ofs << stu.gPhy;
	ofs << ',';
	ofs << stu.gChem;
	ofs << '\n';

	return ofs;
}

//重载>>运算符
std::ifstream& operator>>(std::ifstream& ifs, Student& stu)
{
	char aLine[LineMaxLen]{ "" };//定义一个字符数组，用来接受一行的文本
	ifs.getline(aLine, sizeof(aLine));//从文件中读取一行文本
	std::string strLine = aLine;//构建一个string对象

	std::vector<std::string> strLineArray = SplitString(strLine);
	stu.ID = strLineArray[0];
	stu.name = strLineArray[1];
	stu.gender = strLineArray[2];
	stu.gMath = static_cast<float>(atof(strLineArray[3].c_str()));
	stu.gPhy = static_cast<float>(atof(strLineArray[4].c_str()));
	stu.gChem = static_cast<float>(atof(strLineArray[5].c_str()));

	return ifs;
}
