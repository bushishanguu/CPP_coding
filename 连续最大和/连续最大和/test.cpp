#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i<n; i++)
	{
		cin >> arr(i);
	}
	int curmax = arr[0];
	int MAX = arr[0];
	for (int i = 1; i<n; ++i)
	{
		curmax = (curmax >= 0 ? curmax + arr(i) : arr(i));
		MAX = max(curmax, MAX);

	}
	cout << MAX << endl

}