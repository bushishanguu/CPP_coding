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
//测试构造函数
void TestDeque1()
{
	//构造空的双端队列
	deque<int> d1;

	//用元素构造
	deque<int> d2(10, 5);
	PrintDeque(d2);

	//用数组的区间构造双端队列
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	deque<int> d3(array, array + sizeof(array) / sizeof(array[0]));
	PrintDeque(d3);

	//用d3拷贝构造d4
	deque<int> d4(d3);
	PrintDeque(d4);

}


//测试deque中的迭代器
void TestDeque2()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	deque<int> d(array, array + sizeof(array) / sizeof(array[0]));


	//迭代器正向打印deque中的元素
	for (auto it = d.cbegin(); it != d.cend; ++it)
		cout << *it << " ";
	cout << endl;
	//auto cit = d.begin();

	//利用反向迭代器逆向打印deque中元素
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