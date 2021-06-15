#include <vector>
#include <string>

std::vector<std::string> SplitString(std::string SourceStr, char sep)
{
	std::vector<std::string> ResultArray;//用来存储所有解析出来的子字符串
	std::string strtmp;	//用来接收子字符串

	//PrevC在遍历源字符串时记录下来当前字符，用来识别连续两个字
	//符都是分隔字符的情况
	char PrevC = '\0';
	for (auto itc = SourceStr.begin(); itc < SourceStr.end(); ++itc)
	{//itc迭代器，依次指向源字符串中的字符
		if (sep == (*itc))//遇到分隔字符
		{
			if (itc == SourceStr.begin())
			{
				ResultArray.push_back(" ");
			}
			else
			{
				if (PrevC != sep)//如果前一个字符不是分隔字符
				{//则当前strtmp存储的是一个有效的字符串，将其压入resultarray
					ResultArray.push_back(strtmp);
				}
				else
				{//如果前一个字符也是分隔字符，则应该往resultarray压入由一个空
				 //格构成的字符串
					ResultArray.push_back(" ");
				}
			}
			strtmp.clear();	//将strtmp清空，准备接收下一个子串的字符
		}
		else
		{//当前字符不是分隔字符，则将其压入strtmp中
			strtmp.push_back(*itc);
		}
		PrevC = (*itc);//记录下当前字符
	}
	if (strtmp.empty())//for循环结束后，如果strtmp中没有字符，则意味着
	{//源字符串是以分隔字符串结尾的（不计空字符）,此时将strtmp置为空格
	 //字符串，即在最后添加一个只有一个空格构成的字符串。
		strtmp = " ";
	}
	ResultArray.push_back(strtmp);	//将最后一个分隔字符后的子串压入resultarray

	return ResultArray;//将存储了所有子串的resultarray返回
}
