#pragma once

#include "Student.h"
#include <vector>

class App
{
public:
	App() = default;
	~App();

	char menu();//���˵�
	//���������и�����������ѧ��
	int FindStu(std::string name);

	//�����������һ��Ԫ�أ�bEndAddΪtrue��ʾ��ĩβ���
	bool AddStu(bool bEndAdd = true);
	bool RemoveStu();//��������ɾ��һ��Ԫ��
	void ShowStu();//��ʾ����������ѧ����Ϣ
	float CourseAverage();//���һ�ſε�ƽ���ɼ�
	int FailedCount();//ĳ�ſβ���������
	void HighestAverage();//ƽ���ɼ���ߵ�ѧ��
	void LowestAverage();//ƽ���ɼ���͵�ѧ��
	void ShowByAver();//�ɴ�С��ƽ���ɼ������Ϣ

	bool WriteFile();
	bool ReadFile();
	Student& InputStu(Student& stu);
private:
	std::vector<Student> StuSet;
public:
	void InitSet();
	float StuAverage();
};

