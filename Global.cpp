#include <vector>
#include <string>

std::vector<std::string> SplitString(std::string SourceStr, char sep)
{
	std::vector<std::string> ResultArray;//�����洢���н������������ַ���
	std::string strtmp;	//�����������ַ���

	//PrevC�ڱ���Դ�ַ���ʱ��¼������ǰ�ַ�������ʶ������������
	//�����Ƿָ��ַ������
	char PrevC = '\0';
	for (auto itc = SourceStr.begin(); itc < SourceStr.end(); ++itc)
	{//itc������������ָ��Դ�ַ����е��ַ�
		if (sep == (*itc))//�����ָ��ַ�
		{
			if (itc == SourceStr.begin())
			{
				ResultArray.push_back(" ");
			}
			else
			{
				if (PrevC != sep)//���ǰһ���ַ����Ƿָ��ַ�
				{//��ǰstrtmp�洢����һ����Ч���ַ���������ѹ��resultarray
					ResultArray.push_back(strtmp);
				}
				else
				{//���ǰһ���ַ�Ҳ�Ƿָ��ַ�����Ӧ����resultarrayѹ����һ����
				 //�񹹳ɵ��ַ���
					ResultArray.push_back(" ");
				}
			}
			strtmp.clear();	//��strtmp��գ�׼��������һ���Ӵ����ַ�
		}
		else
		{//��ǰ�ַ����Ƿָ��ַ�������ѹ��strtmp��
			strtmp.push_back(*itc);
		}
		PrevC = (*itc);//��¼�µ�ǰ�ַ�
	}
	if (strtmp.empty())//forѭ�����������strtmp��û���ַ�������ζ��
	{//Դ�ַ������Էָ��ַ�����β�ģ����ƿ��ַ���,��ʱ��strtmp��Ϊ�ո�
	 //�ַ���������������һ��ֻ��һ���ո񹹳ɵ��ַ�����
		strtmp = " ";
	}
	ResultArray.push_back(strtmp);	//�����һ���ָ��ַ�����Ӵ�ѹ��resultarray

	return ResultArray;//���洢�������Ӵ���resultarray����
}
