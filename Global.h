#pragma once

#include <vector>
#include <string>

const std::string FileName = "stu_data.txt";

const int LineMaxLen(1024);

//���÷ָ���sep��string�ַ������������ַ�����������string vector������
std::vector<std::string> SplitString(std::string sourcestr, char sep = ',');
