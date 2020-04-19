#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	while (getline(cin, str))
	{
		int len = str.length();
		for (int i = 0; i<len; ++i)
		{
			if (str[i] >= '0'&&str[i] <= '9')
				cout << str[i];

		}
		cout << endl;
	}
	return 0;
}