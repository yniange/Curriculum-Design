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
		std::cout << "**���ѧ����Ϣ---------------------A**\n";
		std::cout << "**ɾ��ָ��ѧ����Ϣ-----------------R**\n";
		std::cout << "**�������ѧ����Ϣ-----------------S**\n";
		std::cout << "**��ѯһ�ſε�ƽ���ɼ�-------------V**\n";
		std::cout << "**��ѯһλͬѧ��ƽ���ɼ�-----------C**\n";
		std::cout << "**��ѯһ�ſεĲ���������-----------N**\n";
		std::cout << "**���ƽ���ɼ���ߵ�ѧ��-----------H**\n";
		std::cout << "**���ƽ���ɼ���͵�ѧ��-----------L**\n";
		std::cout << "**��ƽ���ɼ��ߵ�˳�����ѧ����Ϣ---B**\n";
		std::cout << "**�˳�-----------------------------X**\n";
		std::cout << "**��ѡ�������";
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
			std::cout << "�������������ѡ��\n";
		}
	}
}

//�����������ң�����Ŀ��ѧ��Ԫ�ص��±꣬δ�ҵ�������-1
int App::FindStu(std::string name)
{
	if (StuSet.empty())
		return -1;

	int len = static_cast<int>(StuSet.size());
	for (int i = 0; i < len; ++i)
	{
		if (name == StuSet[i].name)
		{//�ҵ���ѧ�������±귵��
			return i;
		}

	}
	return -1;//δ�ҵ���ѧ��
}

bool App::AddStu(bool bEndAdd)
{
	if (bEndAdd)
	{
		std::cout << "������� " << StuSet.size() + 1 << " λѧ������Ϣ\n";
		Student stu;
		InputStu(stu);
		StuSet.push_back(stu);
		std::cout << "��ӳɹ���\n\n";
		return true;
	}
	else
	{
		std::cout << "����λͬѧ֮ǰ/�����һλͬѧ����Ϣ��\n������������";
		std::string name;
		getchar();
		getline(std::cin, name);
		int iTar = FindStu(name);//����
		if (-1 == iTar)
		{
			std::cout << "δ�ҵ�Ŀ��ͬѧ���������ʧ�ܣ�\n\n";
			return false;
		}
		else
		{
			char c;
			while (true)
			{
				std::cout << "�� " << name
					<< " ֮ǰ����֮�������ͬѧ��Ϣ����ǰ�������롰B�����������롰A��\n";
				std::cin >> c;
				if ('b' == c || 'B' == c || 'a' == c || 'A' == c)
				{
					break;
				}
				else
				{
					std::cout << "�������������ѡ�������\n";
				}
			}
			std::cout << "������� " << StuSet.size() + 1 << " λѧ������Ϣ\n";
			Student stu;
			InputStu(stu);
			switch (c)
			{
			case 'B':
			case 'b':
			{//֮ǰ����
				StuSet.insert(StuSet.begin() + iTar, stu);
				break;
			}
			case 'A':
			case 'a':
			{//֮�����
				StuSet.insert(StuSet.begin() + iTar + 1, stu);
				//break;
			}
			}
			std::cout << "����ɹ���\n\n";
			return true;
		}
	}
}

//ɾ��һ��ѧ��
bool App::RemoveStu()
{
	if (StuSet.empty())
	{
		std::cout << "�����ݣ�ɾ������ʧ�ܣ�\n\n";
		return false;
	}

	std::cout << "�������ɾ��ͬѧ��������";
	std::string name;
	getchar();
	getline(std::cin, name);
	int iTar = FindStu(name);
	if (-1 == iTar)
	{
		std::cout << "δ�ҵ���ѧ����Ϣ��ɾ������ʧ�ܣ�\n\n";
		return false;
	}

	StuSet.erase(StuSet.begin() + iTar);

	std::cout << name << "���ɹ�ɾ����\n\n";
	return true;
}

//���
void App::ShowStu()
{
	if (StuSet.empty())
	{
		std::cout << "Ŀǰ��ѧ������\n";
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
		std::cout << "û��ѧ����Ϣ�����β���ȡ����\n";
		return 0.0f;
	}

	std::cout << "��ѯ���ſγ̵�ƽ���ɼ���\n";
	char sel;
	while (true)
	{
		std::cout << "��ѧ��������1\n";
		std::cout << "����������2\n";
		std::cout << "��ѧ��������3\n";
		std::cout << "��ѡ��";
		std::cin >> sel;
		if ('1' == sel || '2' == sel || '3' == sel)
			break;
		else
			std::cout << "�������������ѡ��\n";
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
		std::cout << "��ѧƽ���ɼ�Ϊ��" << aver << std::endl;
		break;
	}
	case '2':
	{
		for (auto t : StuSet)
		{
			aver += t.gPhy;
		}
		aver /= StuSet.size();
		std::cout << "����ƽ���ɼ�Ϊ��" << aver << std::endl;
		break;
	}
	case '3':
	{
		for (auto t : StuSet)
		{
			aver += t.gChem;
		}
		aver /= StuSet.size();
		std::cout << "��ѧƽ���ɼ�Ϊ��" << aver << std::endl;
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
		std::cout << "û��ѧ����Ϣ�����β���ȡ����\n";
		return 0;
	}

	std::cout << "��ѯ���ſγ̵Ĳ�����������\n";
	char sel;
	while (true)
	{
		std::cout << "��ѧ��������1\n";
		std::cout << "����������2\n";
		std::cout << "��ѧ��������3\n";
		std::cout << "��ѡ��";
		std::cin >> sel;
		if ('1' == sel || '2' == sel || '3' == sel)
			break;
		else
			std::cout << "�������������ѡ��\n";
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
		std::cout << "��ѧ����������Ϊ��" << fcount << std::endl;
		break;
	}
	case '2':
	{
		for (auto t : StuSet)
		{
			if (t.gPhy < 60)
				fcount++;
		}
		std::cout << "������������Ϊ��" << fcount << std::endl;
		break;
	}
	case '3':
	{
		for (auto t : StuSet)
		{
			if (t.gChem < 60)
				fcount++;
		}
		std::cout << "��ѧ����������Ϊ��" << fcount << std::endl;
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
		std::cout << "û��ѧ����Ϣ�����β���ȡ����\n";
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
	std::cout << StuSet[indexmax].name << " ��ƽ���ɼ���ߣ���ѧ��" << StuSet[indexmax].gMath
		<< " ������" << StuSet[indexmax].gPhy << " ����ѧ��" << StuSet[indexmax].gChem
		<< " ��ƽ���ɼ���" << StuSet[indexmax].Average() << std::endl << std::endl;
}

void App::LowestAverage()
{
	if (StuSet.empty())
	{
		std::cout << "û��ѧ����Ϣ�����β���ȡ����\n";
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
	std::cout << StuSet[indexmin].name << " ��ƽ���ɼ���ͣ���ѧ��" << StuSet[indexmin].gMath
		<< " ������" << StuSet[indexmin].gPhy << " ����ѧ��" << StuSet[indexmin].gChem
		<< " ��ƽ���ɼ���" << StuSet[indexmin].Average() << std::endl << std::endl;
}

void App::ShowByAver()
{
	if (StuSet.empty())
	{
		std::cout << "û��ѧ����Ϣ�����β���ȡ����\n";
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

	//�ļ���ͷһ��˵��������
	std::string strTmp = "ѧ����Ϣ����ϵͳ\n";
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
	//�������
	StuSet.clear();
	//�ж��ļ�stu_data.txt�Ƿ��Ѵ���
	//_access_s�ж������ļ��Ƿ����
	if (0 != _access_s(FileName.c_str(), 0))
	{
		return false;
	}

	//���ļ���ѧ������������
	char aLine[LineMaxLen]{ "" };
	std::ifstream iFile(FileName);

	iFile.getline(aLine, sizeof(aLine));//�ļ���һ�У���Ч������

	iFile.getline(aLine, sizeof(aLine));//�ļ��ڶ��У�һ������������ѧ������
	std::string str(aLine);
	int iCount = stoi(str);//ѧ������
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
	std::cout << "ѧ�ţ�";
	std::cin >> stu.ID;
	std::cout << "������";
	getchar();
	getline(std::cin, stu.name);
	std::cout << "�Ա�";
	std::cin >> stu.gender;
	std::cout << "��ѧ�ɼ���";
	std::cin >> stu.gMath;
	std::cout << "����ɼ���";
	std::cin >> stu.gPhy;
	std::cout << "��ѧ�ɼ���";
	std::cin >> stu.gChem;

	return stu;
}

//ϵͳ����ǵ�һ�����У�������������Ϊϵͳ�ĳ�ʼ����
void App::InitSet()
{
	StuSet.clear();
	Student stu;
	std::string strid[]{ "001","002", "003", "004", "005", "006" };
	std::string strname[]{ "����","����","����","����","����","Ǯ��" };
	std::string strgen[]{ "��","Ů","��","Ů","��","Ů" };
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
		std::cout << "û��ѧ����Ϣ�����β���ȡ����\n";
		return 0.0f;
	}

	std::cout << "��ѯ��λͬѧ��ƽ���ɼ���\n";
	std::string na;
	int stuIndex;
	while (true)
	{
		std::cin >> na;
		if ("X" == na || "x" == na)
		{
			std::cout << "����ȡ����\n\n";
			return 0.0f;
		}
		stuIndex = FindStu(na);
		if (-1 != stuIndex)
			break;
		else
			std::cout << "û�� " << na << " ��λͬѧ��������ѯ�밴x����س�����������������ѧ��������\n";
	}

	float aver = StuSet[stuIndex].Average();
	std::cout << na << " ��ƽ���ɼ�Ϊ��" << aver << std::endl << std::endl;
	return aver;
}
