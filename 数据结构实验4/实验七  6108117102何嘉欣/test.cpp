#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
using namespace std;

//Ã°ÅÝËã·¨£¬¼ÓÈë½»»»±êÖ¾·û
void BubbleSort2(int a[], int n) {
	for (int limit = n - 1; limit > 0; limit--) {
		bool flag = false;
		for (int j = 0; j < limit; j++) {
			if (a[j + 1] < a[j]) {
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
				flag = true;
			}
		}
		if (!flag) break;
	}
}

//Ö±½Ó²åÈëÅÅÐòËã·¨
void InsertSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		if (a[i] < a[i - 1]) {
			int j = i - 1;
			int tmp = a[i];
			while (tmp < a[j]) {
				a[j + 1] = a[j];
				j--;
			}
			a[j + 1] = tmp;
		}
	}
}

//Ñ¡ÔñÅÅÐò·¨
void SelectSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int key, tmp;
		key = i;
		for (int j = i + 1; j < n - 1; j++) {
			if (a[j] <a[key]) {
				key = j;
			}
		}
		if (key != i) {
			tmp = a[key];
			a[i] = a[key];
			a[key] = tmp;
		}
	}
}

int main()
{
	int a[8] = { 60, 32, 65, 97, 9, 13, 27, 80 };
	printf("Ã°ÅÝÅÅÐò\n");
	BubbleSort2(a,8);
	for (int j = 0; j < 8; j++)
	{
		printf("%d\t", a[j]);
	}
	printf("\n");
	printf("²åÈëÅÅÐò\n");
	InsertSort(a,8);
	for (int j = 0; j < 8; j++)
	{
		printf("%d\t", a[j]);
	}
	printf("\n");
	printf("Ñ¡ÔñÅÅÐò\n");
	SelectSort(a, 8);
	for (int j = 0; j < 8; j++)
	{
		printf("%d\t", a[j]);
	}
	printf("\n");
	system("pause");
	return 0;
}