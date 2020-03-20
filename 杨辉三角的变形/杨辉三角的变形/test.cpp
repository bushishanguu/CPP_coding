#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n, m, i, j;
	while (cin >> n)
	{
		m = 2 * n - 1;
		vector<vector<int>>num(n, vector<int>(m, 0));//行列全部初始化为0
		num[0][0] = 1;//第一个数字为1
		for (i = 1; i<n; ++i)//求第1行到第n-1行的值
		{
			num[i][0] = num[i][2 * i] = 1; //每行的第0列和最后一列都是1
			for (j = 1; j < 2 * i; ++j) //求某一行第1列到第2i-1列(倒数第二列)的值
			{
				if (j == 1) //当前行第一列值为上一行第0列+第1列
					num[i][j] = num[i - 1][j - 1] + num[i - 1][j];
				else //其余列为三个数的和(左上角j-2，正上方j-1，右上角j)
					num[i][j] = num[i - 1][j - 2] + num[i - 1][j - 1] + num[i - 1][j];
			}
		}
		for (i = 1; i < m - 1; ++i) //在第n行找第一个偶数的位置
		{
			if (!((num[n - 1][i]) & 1) && num[n - 1][i] != 0) //如果是可以被2整除且不是0说明是偶数，返回其位置
			{
				cout << i + 1 << endl;
				break;
			}
		}
		if (i == m) //找不到返回-1
			cout << -1 << endl;
	}
	return 0;
}