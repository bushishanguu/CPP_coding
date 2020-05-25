#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void shellsort(int b[], int count)
{
	int set[3] = { 5, 2, 1 };
	int i, j, getset, temp, j2;
	for (i = 0; i<3; i++)
	{
		getset = set[i];
		for (j = getset; j<count; j++)  
		{                                
			j2 = j;
			for (; b[j2]<b[j2 - getset] && (j2 - getset) >= 0; j2 = j2 - getset)
			{
				temp = b[j2];
				b[j2] = b[j2 - getset];
				b[j2 - getset] = temp;
			}
		}
	}
}

int main()
{
	int a[100], n;
	printf("产生的100个随机数：\n");
	
	srand((unsigned)time(NULL));
	for (n = 0; n<100; n++)
	{
		a[n] = rand() % 491 + 10;
		printf("%d\t", a[n]);
		if (n == 9 || n == 19 || n == 29 || n == 39 || n == 49 || n == 59 || n == 69 || n == 79 || n == 89 || n == 99)printf("\n");
	}
	shellsort(a, 100);
	printf("希尔排序后的结果\n");
	for (n = 0; n<100; n++)
	{
		printf("%d\t", a[n]);
		if (n == 9 || n == 19 || n == 29 || n == 39 || n == 49 || n == 59 || n == 69 || n == 79 || n == 89 || n == 99)printf("\n");
	}
	system("pause");

}
