#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int main(){
	int year, month, day;
	int monthday[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	while (cin >> year >> month >> day)
	{
		int sum = 0;
		monthday[2] = 28;
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)//�ж�����
		{
			monthday[2] = 29;
		}
		for (int i = 1; i < month; i++)//ǰ�����µ�����
		{
			sum += monthday[i];
		}
		sum += day;//���ϱ��µ�����
		cout << sum << endl;
	}
}