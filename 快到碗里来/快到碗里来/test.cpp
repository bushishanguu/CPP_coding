#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main()
{
	double l, r;
	while (cin >> l >> r)
	{
		if (l>6.28*r)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return 0;
}