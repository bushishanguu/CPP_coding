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

