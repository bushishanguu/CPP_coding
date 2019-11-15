#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//void PrintVector(const vector<int>& v)
//{
//	//const对象使用const迭代器进行遍历打印
//	vector<int>::const_iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
//
//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	//使用迭代器进行遍历打印
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	//使用迭代器进行修改
//	it = v.begin();
//	while (it != v.begin())
//	{
//		*it *= 2;
//		++it;
//	}
//
//	//使用反向迭代器进行遍历再打印
//	vector<int>::reverse_iterator rit = v.rbegin();
//	while (rit != v.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout<< endl;
//	PrintVector(v);
//


//int main()
//{
//	//vector空间增长的问题
//	size_t sz;
//	vector<int> foo;
//	sz = foo.capacity();
//	cout << "making foo grow:\n";
//	for (int i = 0; i < 100; ++i)
//	{
//		foo.push_back(i);
//		if (sz != foo.capacity()){
//			sz = foo.capacity();
//			cout << "capacity changed:" << sz << '\n';
//		}
//	}
//
//
//	system("pause");
//	return 0;
//}


//vector::reserve
//int main()
//{
//	size_t sz;
//	vector<int> foo;
//	sz = foo.capacity();
//	cout << "making foo grow:\n";
//	for (int i = 0; i < 100; ++i)
//	{
//		foo.push_back(i);
//		if (sz != foo.capacity())
//		{
//			sz = foo.capacity();
//			cout << "capacity changed:" << sz << '\n';
//		}
//	}
//	vector<int> bar;
//	sz = bar.capacity();
//	bar.reserve(100);
//	cout << "making bar grow:\n";
//	for (int i = 0; i < 100; ++i)
//	{
//		bar.push_back(i);
//		if (sz != bar.capacity())
//		{
//			sz = bar.capacity();
//			cout << "capacity changed:" << sz << '\n';
//		}
//	}
//	system("pause");
//	return 0;
//}


int main()
{
	vector<int> myvector;
	for (int i = 1; i < 10; i++)
	{
		myvector.push_back(i);

		myvector.resize(5);
		myvector.resize(8, 100);
		myvector.resize(12);

		cout << "myvector contains:";
		for (int i = 0; i < myvector.size(); i++)
			cout << ' ' << myvector[i];
		cout << '\n';
		system("pause");
		return 0;
	}
}