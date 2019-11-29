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
	for (auto it = d.cbegin(); it != d.cend(); ++it)
		cout << *it << " ";
	cout << endl;
	auto cit = d.begin();

	//���÷�������������ӡdeque��Ԫ��
	for (auto it = d.crbegin(); it != d.crend(); ++it)
		cout << *it << " ";
	cout << endl;
	
}

void TestDeque3()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	deque<int> d1(array, array + sizeof(array) / sizeof(array[0]));

	//����β�壬ͷ�壬��ӡ
	d1.push_back(6);
	d1.push_front(2);
	PrintDeque(d1);

	cout << d1.size() << endl;
	cout << d1.front() << endl;
	cout << d1.back() << endl;

	//��beginλ�ò���Ԫ��
	d1.insert(d1.begin(), 0);
	PrintDeque(d1);


	//ɾ����βԪ��
	d1.pop_front();
	d1.pop_back();
	d1.erase(d1.begin());
	PrintDeque(d1);

	//���Ԫ��
	d1.clear();
		cout << d1.size() << endl;
}



//����
#include<algorithm>
void TestDequeSort()
{
	int array[] = { 5, 2, 1, 9, 6, 3, 8, 7, 4, 0 };
	deque<int> d(array, array + sizeof(array) / sizeof(array[0]));
	PrintDeque(d);

	//���ñ�׼�㷨������������
	sort(d.begin(), d.end());
	PrintDeque(d);


}


int main()
{
	TestDeque1();
	TestDeque2();
	TestDeque3();
	system("pause");
	return 0;

}