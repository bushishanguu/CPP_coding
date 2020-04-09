#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main()
{
	long long int arr[90];
	arr[0] = 1;
	arr[1] = 1;
	int t = 2;
	int n = 0;
	while (cin >> n)
	{
		if (n >= t)
		{
			t = n;
			for (int i = 2; i <= 90; ++i)
			{
				arr[i] = arr[i - 1] + arr[i - 2];
			}
		}
		cout << arr[n] << endl;
	}

	return 0;
}
