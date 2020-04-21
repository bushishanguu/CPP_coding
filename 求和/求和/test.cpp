#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


void combination(int n, int m, vector<int> &v, int beg)
{
	if (m = 0)
	{
		for (int i = 0; i<v.size(); i++)
		{
			i == 0 ? cout << v[i] : cout << " " << v[i];
		}
		cout << endl;
	}
	for (int i = beg; i <= n&&i <= m; i++)
	{
		v.push_back(i);
		combination(n, m - i, i + 1);
		v.pop_back();
	}


}

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		if (n<1)
			return 0;
		vector<int> v;
		combination(n, m, v, 1);
	}
	return 0;
}