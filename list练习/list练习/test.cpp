#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
#include<vector>
#include<stdlib.h>
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


void PrintList(list<int>& l)
{
	for (auto& e : l)
		cout << e << " ";
	cout << endl;
}

void TestList1()
{
	int array[] = { 1, 2, 3 };
	list<int> L(array, array + sizeof(array) / sizeof(array[0]));
	L.push_back(4);
	L.push_front(0);
	PrintList(L);

	L.pop_back();
	L.pop_front();
	PrintList(L);
}

void TestList3()
{
	int array1[] = { 1, 2, 3 };
	list<int> L(array1, array1 + sizeof(array1) / sizeof(array1[0]));
	//获取链表中的第二个节点
	auto pos = ++L.begin();
	cout << *pos << endl;
	//在pos前插入值为4的元素
	L.insert(pos, 4);
	PrintList(L);
	//在pos前插入5个值为5的元素
	L.insert(pos, 5, 5);
	PrintList(L);
	//在pos前插入[v.begin(),v.end]区间中的元素
	vector<int> v{ 7, 8, 9 };
	L.insert(pos, v.begin(), v.end());
	PrintList(L);

	//删除pos位置上的元素
	L.erase(pos);
	PrintList(L);
	//删除list中[begin,end)区间中的元素，删除list中所有的元素
	L.erase(L.begin(), L.end());
	PrintList(L);
}

//void TestList4()
//{
//	//构造list
//	int array1[] = { 1, 2, 3 };
//	list<int> l1(array1, array1 + sizeof(array1) / sizeof(array1[0]));
//	PrintList(l1);
//
//	//交换l1和l2中的元素
//	l1.swap(l2);
//	PrintList(l1);
//	PrintList(l2);
//
//}

int main()
{
	//TestList1();
	TestList3();
	system("pause");
	return 0;

}