#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
void SortAges(int ages[], int length)
{
	if (ages == NULL || length <= 0)
		return;
	const int oldestAge = 99;
	int timeOfAge[oldestAge + 1]; //统计每个年龄出现的次数

	for (int i = 0; i <= oldestAge; ++i)
		timeOfAge[i] = 0;

	for (int i = 0; i < length; ++i)
	{
		int age = ages[i];
		if (age<0 || age>oldestAge)
			throw new exception("age out of range.");
		++timeOfAge[age];
	}

	int index = 0;
	for (int i = 0; i <= oldestAge; ++i)
	{
		for (int j = 0; j < timeOfAge[i]; ++j)
		{
			ages[index] = i;
			++index;
		}
	}
}