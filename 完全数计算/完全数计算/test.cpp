#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		for (int i = 1; i <= n; i++)
		{
			int sum = 0;
			for (int j = 1; j<i; j++)
			{
				if (i%j == 0)
					sum = sum + j;
			}
			if (sum == i)
				count++;
		}
		cout << count << endl;
	}
	return 0;
}