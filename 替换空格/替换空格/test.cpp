#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
using namespace std;
//length为字符数组string的总容量
void ReplaceBlank(char string[], int length)
{
	if (string == NULL &&length <= 0)
		return;
//originalLength为字符串string的实际长度
	int originalLength = 0;
	int numberOfBlank = 0;
	int i = 0;
	while (string[i] != '\0')
	{
		++originalLength;
		if (string[i] == ' ')
			++numberOfBlank;
		++i;	
	}
//newLength为把空格替换成"%20"之后的长度
	int newLength = originalLength + numberOfBlank * 2;
	if (newLength > length)
		return;
	int indexOfOriginal = originalLength;
	int indexOfNew = newLength;
	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
	{
		if (string[indexOfOriginal] == ' ')
		{
			string[indexOfNew--] = '0';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';
		}
		else
		{
			string[indexOfNew--] = string[indexOfOriginal];
		}
		--indexOfOriginal;
	}

}