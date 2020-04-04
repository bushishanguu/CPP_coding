#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{
		for (int i = 0; i<str.size(); ++i)
		{
			if (str[i] == ' ')
				i++;
			str[i] -= 5;
			if (str[i]<'A')
				str[i] += 26;
		}
		cout << str << endl;
	}
	return 0;
}