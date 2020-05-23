#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void shellsort(int b[], int count)
{
	int set[3] = { 5, 2, 1 };//设置增量
	int i, j, getset, temp, j2;
	for (i = 0; i<3; i++)
	{
		getset = set[i];//获取增量 
		for (j = getset; j<count; j++)  // 这种方式并不是先分组再插入排序
		{                       // 是一边分组一边插入排序，多组轮换插入排序         
			j2 = j;
			for (; b[j2]<b[j2 - getset] && (j2 - getset) >= 0; j2 = j2 - getset)//元素在自己的组进行插入排序
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
	//直接用rand()会产生伪随机数，编译一次多次输出结果一样
	srand((unsigned)time(NULL));//把当前时间设置为随机函数的种子，每次产生的数不一样
	for (n = 0; n<100; n++)
	{
		a[n] = rand() % 491 + 10;//随机数区间设置为10到500
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
