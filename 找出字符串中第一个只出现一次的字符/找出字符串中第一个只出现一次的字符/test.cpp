#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	while (getline(cin, s))
	{
		int count[256] = { 0 };
		for (int i = 0; i<s.size(); i++)
		{
			count[s[i]]++;
		}
		int i = 0;
		for (i = 0; i<s.size(); i++)
		{
			if (count[s[i]] == 1)
			{
				cout << s[i] << endl;
				break;
			}
		}
		if (i >= s.size())
			cout << -1 << endl;
	}
	return 0;
}