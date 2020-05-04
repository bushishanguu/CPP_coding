#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

int getsubarraymaxsum(vector<int>& v)
{
	int maxsum = 0xffffffff;
	int cursum = 0;

	for (size_t i = 0; i < v.size(); ++i)
	{
		if (cursum < 0)
		{
			cursum = v[i];
		}
		else
		{
			cursum += v[i];
		}
		if (cursum>maxsum)
		{
			maxsum = cursum;
		}
	}
	return maxsum;
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		vector<int> v;
		v.resize(n);
		for (size_t i = 0; i < n; ++i)
			cin >> v[i];
		cout << getsubarraymaxsum(v) << endl;
	}
	return 0;
}