#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

void PrintVector(const vector<int>& v)
{
	//const对象使用const迭代器进行遍历打印
	vector<int>::const_iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	//使用迭代器进行遍历打印
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//使用迭代器进行修改
	it = v.begin();
	while (it != v.begin())
	{
		*it *= 2;
		++it;
	}

	//使用反向迭代器进行遍历再打印
	vector<int>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout<< endl;
	PrintVector(v);


	system("pause");
	return 0;
}

