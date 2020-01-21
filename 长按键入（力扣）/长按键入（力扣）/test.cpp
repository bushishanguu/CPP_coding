#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	bool isLongPressedName(string name, string typed) {
		//对于name的字符串，两者相等时，同时++， 两者不等时，typed后移。
		if (name == typed) //先进行预判断  
		{
			return true;
		}
		if (name.size() > typed.size())
		{
			return false;
		}
		int i = 0;
		int j = 0;
		while (i < name.size() && j < typed.size())
		{
			if (name[i] == typed[j])//对于name的字符串，两者相等时，同时++，
			{
				++i;
				++j;
			}
			else//两者不等时，typed后移
			{
				++j;
			}
		}
		while (j < typed.size())//把name扫描完之后，把typed剩余的尾巴再判断一下。    
		{
			if (name[i - 1] != typed[j])   return false;
			else
				++j;
		}
		return i == name.size();
	}
};