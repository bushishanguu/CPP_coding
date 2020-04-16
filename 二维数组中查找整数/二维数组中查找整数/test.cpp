#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

void find(int a[][4], int rows, int cols, int number)
{
	if (rows > 0 && cols > 0)
	{
		int row = 0, col = cols - 1;
		while (row < rows&&col >= 0)
		{
			if (a[row][col] == number)
			{
				cout << row << " " << col << endl;
				break;
			}
			else
			if (a[row][col] < number)
				--col;
			else
				++row;
		}
		if (row == rows || col == -1)
			cout << " no" << endl;
	}
}

void main()
{
	int a[4][4] = {
		15, 11, 8, 6,
		13, 10, 7, 4,
		12, 9, 4, 2,
		9, 8, 2, 1 };

	find(a, 4, 4, 100); //not exist. 
	find(a, 4, 4, 7);
	system("pause");
}
