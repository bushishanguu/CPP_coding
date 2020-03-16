#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	int i = 0;
	int count = 1;//首先根据空格和双引号判断参数个数，初始值为1
	while (getline(cin, str))
	{
		for (i = 0; i<str.size(); ++i)
		{
			if (str[i] == '"')//遇到双引号直接向后遍历到下一个个双引号
			{
				do
				{
					i++;
				} while (str[i] != '"');
			}
			else if (str[i] == ' ')//遇到空格则参数个数+1
				++count;
		}
		cout << count << endl;
		int temp = 0;//输出分解后的参数，定义一个标志来判断当前是否在双引号内
		for (i = 0; i < str.size(); ++i)
		{
			if (str[i] == '"')
				temp ^= 1;

			if (str[i] != ' '&&str[i] != '"')//不是空格或双引号直接打印
				cout << str[i];
			else if (str[i] == ' ')
			{
				if (temp)
					cout << str[i];//双引号中的空格打印
				else
					cout << endl;//双引号外的空格用换行代替
			}
		}
	}
	return 0;
}
