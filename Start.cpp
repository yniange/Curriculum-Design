#include <iostream>
#include "Student.h"
#include "App.h"
#include <io.h>
#include "Global.h"

App theApp;

int main(void)
{
	std::cout << "****** ��ӭ����ѧ����Ϣ����ϵͳ ******" << std::endl;
	//����ǵ�һ������ϵͳ��ͨ��̽�������ļ��Ƿ���ڣ������ó�ʼ���ݡ�

	//�ж��ļ�stu_data.txt�Ƿ��Ѵ���
	//_access_s�ж������ļ��Ƿ����
	if (0 != _access_s(FileName.c_str(), 0))
	{//��������ļ������ڣ����ó�ʼ��������StuSet
		theApp.InitSet();
	}
	else
	{//��������ļ����ڣ���������ļ��ж�ȡ�洢���ļ��е�ѧ������
		theApp.ReadFile();
	}

	while (true)
	{
		switch (theApp.menu())
		{
		case 'A':
		{//����
			theApp.AddStu(false);
			break;
		}
		case 'R':
		{//ɾ��
			theApp.RemoveStu();
			break;
		}
		case 'S':
		{//���
			theApp.ShowStu();
			break;
		}
		case 'V':
		{
			//һ�ſε�ƽ���ɼ�
			theApp.CourseAverage();
			break;
		}
		case 'C':
		{
			//һλͬѧ��ƽ���ɼ�
			theApp.StuAverage();
			break;
		}
		case 'N':
		{
			//һ�ſεĲ���������
			theApp.FailedCount();
			break;
		}
		case 'H':
		{
			//ƽ���ɼ���ߵ�ѧ��
			theApp.HighestAverage();
			break;
		}
		case 'L':
		{
			//ƽ���ɼ���͵�ѧ��
			theApp.LowestAverage();
			break;
		}
		case 'B':
		{
			theApp.ShowByAver();
			break;
		}
		case 'X':
		{//�˳�
			theApp.WriteFile();	//�������ǰ������ǰ��ѧ����Ϣ�洢�������ļ���
			std::cout << "ϵͳ�˳����ټ���" << std::endl;
			return 0;
		}
		}
	}
}