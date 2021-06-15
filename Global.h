#pragma once

#include <vector>
#include <string>

const std::string FileName = "stu_data.txt";

const int LineMaxLen(1024);

//利用分隔符sep将string字符串解析成子字符串，存入至string vector容器中
std::vector<std::string> SplitString(std::string sourcestr, char sep = ',');
