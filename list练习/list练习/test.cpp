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
//	//������Ϊ���������乹��l5
//	int array[] = { 16, 2, 77, 29 };
//	list<int> l5(array, array + sizeof(array) / sizeof(int));
//
//	//�õ�������ʽ��ӡl5�е�Ԫ��
//	for (list<int>::iterator it = l5.begin(); it != l5.end(); it++)
//		cout << *it << " ";
//	cout << endl;
//
//	//C++11��Χfor�ķ�ʽ����
//	for (auto& e : l5)
//		cout << e << " ";
//
//	cout << endl;
//	system("pause");
//	return 0;
//}


//list iterator��ʹ��
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
//	//ʹ���������������list�е�Ԫ��
//	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
//		cout << *it << " ";
//	cout << endl;
//	//ʹ�÷�������������ӡlist�е�Ԫ��
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
	//��ȡ�����еĵڶ����ڵ�
	auto pos = ++L.begin();
	cout << *pos << endl;
	//��posǰ����ֵΪ4��Ԫ��
	L.insert(pos, 4);
	PrintList(L);
	//��posǰ����5��ֵΪ5��Ԫ��
	L.insert(pos, 5, 5);
	PrintList(L);
	//��posǰ����[v.begin(),v.end]�����е�Ԫ��
	vector<int> v{ 7, 8, 9 };
	L.insert(pos, v.begin(), v.end());
	PrintList(L);

	//ɾ��posλ���ϵ�Ԫ��
	L.erase(pos);
	PrintList(L);
	//ɾ��list��[begin,end)�����е�Ԫ�أ�ɾ��list�����е�Ԫ��
	L.erase(L.begin(), L.end());
	PrintList(L);
}

//void TestList4()
//{
//	//����list
//	int array1[] = { 1, 2, 3 };
//	list<int> l1(array1, array1 + sizeof(array1) / sizeof(array1[0]));
//	PrintList(l1);
//
//	//����l1��l2�е�Ԫ��
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