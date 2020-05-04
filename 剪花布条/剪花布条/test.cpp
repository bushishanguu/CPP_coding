#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s, t;
	while (cin >> s >> t)
	{
		int count = 0;
		size_t pos = 0;
		while ((pos = s.find(t, pos)) != string::npos)
		{
			pos += t.size();
			++count;
		}
		cout << count << endl;
	}
	return 0;
}