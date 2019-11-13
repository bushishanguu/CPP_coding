#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<functional>
#include<queue>
#include<list>
using namespace std;

void main()
{
	int ar[] = { 3, 2, 7, 6, 0, 4, 1, 9, 8, 5 };
	int n = sizeof(ar) / sizeof(int);
	list<int> mylist(ar, ar + n);

	mylist.sort();

	for (auto e : mylist)
		cout << e << " ";
	cout << endl;
}

/*
void main()
{
int ar[] = {3, 2, 7, 6, 0, 4, 1, 9, 8, 5};
int n = sizeof(ar) / sizeof(int);
priority_queue<int> q;
priority_queue<int> q(ar, ar+n); //?ио??
priority_queue<int,vector<int>, greater<int> > q(ar, ar+n);

cout<<"size = "<<q.size()<<endl;
cout<<"top = "<<q.top()<<endl;
q.pop();
cout<<"top = "<<q.top()<<endl;
}
/*
class Date
{
public:
Date(int year, int month, int day)
: m_year(year), m_month(month), m_day(day)
{}
~Date()
{}
public:
bool operator<(const Date &d)const
{
if(m_year < d.m_year)
return true;
else if(m_year > d.m_year)
return false;
if(m_month < d.m_month)
return true;
else if(m_month > d.m_month)
return false;
if(m_day < d.m_day)
return true;
else if(m_day > d.m_day)
return false;
return false;
}
private:
int m_year;
int m_month;
int m_day;
};
void main()
{
priority_queue<Date> q;
q.push(Date(2015,11,13));
q.push(Date(2019,3,5));
}
