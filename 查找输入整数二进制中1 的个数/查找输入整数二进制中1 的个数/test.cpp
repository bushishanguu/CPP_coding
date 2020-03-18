#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int main()
{
	int num;
	while (cin >> num)
	{
		int count = 0;
		while (num)
		{
			if (num & 1)
			{
				count++;
			}
			num = num >> 1;
		}
		cout << count << endl;
	}
	return 0;
}