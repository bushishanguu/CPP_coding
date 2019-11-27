#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<deque>
using namespace std;

void PrintDeque(const deque<int>& d)
{
	for (const auto& e : d)
		cout << e << " ";
	cout << endl;
}
//���Թ��캯��
void TestDeque1()
{
	//����յ�˫�˶���
	deque<int> d1;

	//��Ԫ�ع���
	deque<int> d2(10, 5);
	PrintDeque(d2);

	//����������乹��˫�˶���
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	deque<int> d3(array, array + sizeof(array) / sizeof(array[0]));
	PrintDeque(d3);

	//��d3��������d4
	deque<int> d4(d3);
	PrintDeque(d4);

}


//����deque�еĵ�����
void TestDeque2()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	deque<int> d(array, array + sizeof(array) / sizeof(array[0]));


	//�����������ӡdeque�е�Ԫ��
	for (auto it = d.cbegin(); it != d.cend; ++it)
		cout << *it << " ";
	cout << endl;
	//auto cit = d.begin();

	//���÷�������������ӡdeque��Ԫ��
	for (auto it = d.crbegin(); it != d.crend(); ++it)
		cout << *it << " ";
	cout << endl;
	
}




int main()
{
	//TestDeque1();
	TestDeque2();
	system("pause");
	return 0;

}