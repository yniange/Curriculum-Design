#pragma once

#include <string>

class Student
{
public:
	std::string ID = "";
	std::string name = "";
	std::string gender = "";
	float gMath = 0.0f;//��ѧ�ɼ�
	float gPhy = 0.0f;//����ɼ�
	float gChem = 0.0f;//��ѧ�ɼ�

	void Show();
	float Average();//��ƽ���ɼ�

	friend std::ofstream& operator<<(std::ofstream& ofs, const Student& stu);
	friend std::ifstream& operator>>(std::ifstream& ifs, Student& stu);
};

