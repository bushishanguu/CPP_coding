#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

int fun(string s)
{
	int ret = 0;
	for (int i = 0; i<s.size(); i++)
	{
		ret = ret * 26 + s[i] - 'a';
	}
	return ret;
}

int main()
{
	string str1, str2;
	int l1, l2;
	while (cin >> str1 >> str2 >> l1 >> l2)
	{
		cout << (fun(str2) - fun(str1) - 1) % 1000007 << endl;
	}
	return 0;
}