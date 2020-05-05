#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long long d[22] = { 0, 0, 1 };
	long long f[22] = { 0, 1, 2 };
	for (int i = 3; i<22; i++)
	{
		d[i] = (i - 1)*(d[i - 1] + d[i - 2]);//错排递推公式
		f[i] = i*f[i - 1];//阶乘的递推公式
	}
	int n;
	while (cin >> n)
	{
		printf("%.2f%%\n", 100.0*d[n] / f[n]);
	}
	return 0;
}