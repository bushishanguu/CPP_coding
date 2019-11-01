#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int main()
{
	double x = 0, y = 1, s;
	cout << "计算两个数之和：" << endl;
	cout << "请输入被加数：";
	cin >> x;
	cout << "请输入加数：";
	cin >> y;
	s = x + y;
	cout << x << "+" << y << "=" << s << endl;
	return 0;
}