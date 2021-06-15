#include "Student.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "Global.h"
#include <iomanip>

void Student::Show()
{
	std::cout << "ѧ�ţ�" << std::setw(3) << ID
		<< "\t������" << std::setw(10) << std::setiosflags(std::ios::left) << name
		<< "\t�Ա�" << gender
		<< "\t��ѧ��" << gMath
		<< "\t����" << gPhy
		<< "\t��ѧ��" << gChem
		<< std::endl;
}

float Student::Average()
{
	return (gMath + gPhy + gChem) / 3.0f;
}

//����<<�����
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

//����>>�����
std::ifstream& operator>>(std::ifstream& ifs, Student& stu)
{
	char aLine[LineMaxLen]{ "" };//����һ���ַ����飬��������һ�е��ı�
	ifs.getline(aLine, sizeof(aLine));//���ļ��ж�ȡһ���ı�
	std::string strLine = aLine;//����һ��string����

	std::vector<std::string> strLineArray = SplitString(strLine);
	stu.ID = strLineArray[0];
	stu.name = strLineArray[1];
	stu.gender = strLineArray[2];
	stu.gMath = static_cast<float>(atof(strLineArray[3].c_str()));
	stu.gPhy = static_cast<float>(atof(strLineArray[4].c_str()));
	stu.gChem = static_cast<float>(atof(strLineArray[5].c_str()));

	return ifs;
}
