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
	for (auto it = d.cbegin(); it != d.cend(); ++it)
		cout << *it << " ";
	cout << endl;
	auto cit = d.begin();

	//利用反向迭代器逆向打印deque中元素
	for (auto it = d.crbegin(); it != d.crend(); ++it)
		cout << *it << " ";
	cout << endl;
	
}

void TestDeque3()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	deque<int> d1(array, array + sizeof(array) / sizeof(array[0]));

	//进行尾插，头插，打印
	d1.push_back(6);
	d1.push_front(2);
	PrintDeque(d1);

	cout << d1.size() << endl;
	cout << d1.front() << endl;
	cout << d1.back() << endl;

	//在begin位置插入元素
	d1.insert(d1.begin(), 0);
	PrintDeque(d1);


	//删除首尾元素
	d1.pop_front();
	d1.pop_back();
	d1.erase(d1.begin());
	PrintDeque(d1);

	//清空元素
	d1.clear();
		cout << d1.size() << endl;
}



//排序
#include<algorithm>
void TestDequeSort()
{
	int array[] = { 5, 2, 1, 9, 6, 3, 8, 7, 4, 0 };
	deque<int> d(array, array + sizeof(array) / sizeof(array[0]));
	PrintDeque(d);

	//利用标准算法进行升序排序
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