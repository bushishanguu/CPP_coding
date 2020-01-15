#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
template<class T,class Container=vector<T>>
class Stack


{
public:
	Stack()
	{}
	void Push(const T& x)
	{
		_con.push_back(x);
	}

	void Pop()
	{
		_con.pop_back();
	}

	const T& Top()
	{
		return _con.back();
	}

	size_t Size()const
	{
		return _con.size();
	}

	bool Empty()const
	{
		return _con.empty();
	}

private:
	Container _con;
};
void TestStack()
{
	Stack<int> s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	s.Push(5);
	s.Push(6);
	cout<<s.Size() << endl;
	cout << s.Top()<<endl;
	while (!s.Empty())
	{
		cout << s.Top() << " ";
		s.Pop();
	}
	cout << endl;

}



int main()
{
	
	TestStack();
	system("pause");
	return 0;
}