#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//void PrintVector(const vector<int>& v)
//{
//	//const����ʹ��const���������б�����ӡ
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
//	//ʹ�õ��������б�����ӡ
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	//ʹ�õ����������޸�
//	it = v.begin();
//	while (it != v.begin())
//	{
//		*it *= 2;
//		++it;
//	}
//
//	//ʹ�÷�����������б����ٴ�ӡ
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
//	//vector�ռ�����������
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


//int main()
//{
//	vector<int> myvector;
//	for (int i = 1; i < 10; i++)
//	{
//		myvector.push_back(i);
//
//		myvector.resize(5);
//		myvector.resize(8, 100);
//		myvector.resize(12);
//
//		cout << "myvector contains:";
//		for (int i = 0; i < myvector.size(); i++)
//			cout << ' ' << myvector[i];
//		cout << '\n';
//		system("pause");
//		return 0;
//	}
//}


//vector��ɾ�Ĳ�

//push_back
//pop_back


//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	v.pop_back();
//	v.pop_back();
//	it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}
//



//#include<algorithm>
//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
//
//	v.insert(pos, 30);
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	pos = find(v.begin(), v.end(), 3);
//	v.erase(pos);
//	it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}


//vector[]+index ��C++11��vector����ʽfor+auto�ı���
//vector ʹ�������ֱ�����ʽ�ǱȽϷ����ݵ�

int main()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + a + sizeof(a) / sizeof(int));
	//ͨ��[]��д��0��λ��
	v[0] = 10;
	cout << v[0] << endl;
	//ͨ��[i]�ķ�ʽ����vector
	for (size_t i = 0; i < v.size(); ++i)
	
		cout << v[i] << ' ';
		cout << endl;
		vector<int>swapv;
		swapv.swap(v);
		cout << "v data :";
		for (size_t i = 0; i < v.size(); ++i)
			cout << v[i] << " ";
		cout << endl;

		cout << "swapv data";
		for (size_t i = 0; i < v.size(); ++i)
			cout << swapv[i] << " ";
		cout << endl;

		for (auto x : v)
			cout << x << " ";
		cout << endl;
		system("pause");
		return 0;
}