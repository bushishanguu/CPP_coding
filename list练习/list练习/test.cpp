#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
using namespace std;

//int main()
//{
//	list<int> l1;
//	list<int> l2(4, 100);
//	list<int> l3(l2.begin(), l2.end());
//	list<int> l4(l3);
//
//
//	//以数组为迭代器区间构造l5
//	int array[] = { 16, 2, 77, 29 };
//	list<int> l5(array, array + sizeof(array) / sizeof(int));
//
//	//用迭代器方式打印l5中的元素
//	for (list<int>::iterator it = l5.begin(); it != l5.end(); it++)
//		cout << *it << " ";
//	cout << endl;
//
//	//C++11范围for的方式遍历
//	for (auto& e : l5)
//		cout << e << " ";
//
//	cout << endl;
//	system("pause");
//	return 0;
//}


//list iterator的使用
//void print_list(const list<int> & l)
//{
//	for (list<int>::const_iterator it = l.begin(); it != l.end(); ++it)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//
//int main()
//{
//	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
//	//使用正向迭代器正向list中的元素
//	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
//		cout << *it << " ";
//	cout << endl;
//	//使用反向迭代器逆向打印list中的元素
//	for (list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); ++it)
//		cout << *it << " ";
//	cout << endl;
//	system("pause");
//	return 0;
//}

