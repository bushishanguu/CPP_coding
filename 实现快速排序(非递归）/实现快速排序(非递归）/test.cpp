#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int Partition(int data[], int length, int start, int end)
{
	if (data == NULL || length <= 0 || start < 0 || end >= length)
		throw new std::exception("Invalid Paraments");

	int index = RandomInRange(start, end);//用来生成一个在start和end之间的随机数
	Swap(&data[index], &data[end]);

	int small = start - 1;
	for (index = start; index < end; ++index)
	{
		if (data[index] < data[end])
		{
			++small;
			if (small != index)
				Swap(&data[index], &data[small]);
		}
	}

	++small;
	Swap(&data[small], &data[end]);
	return small;
}