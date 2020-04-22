#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		map<char, int>A, B;
		for (int i = 0; i<str1.size(); i++)
		{
			A[str1[i]]++;
		}
		for (int i = 0; i<str2.size(); i++)
		{
			B[str2[i]]++;
		}
		for (int i = 'A'; i <= 'Z'; i++)
		{
			if (B[i]>A[i])
			{
				cout << "No" << endl;
				break;
			}
			if (i == 'Z')
				cout << "Yes" << endl;
		}
	}
	return 0;
}