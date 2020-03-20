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
		vector<vector<int>>num(n, vector<int>(m, 0));//����ȫ����ʼ��Ϊ0
		num[0][0] = 1;//��һ������Ϊ1
		for (i = 1; i<n; ++i)//���1�е���n-1�е�ֵ
		{
			num[i][0] = num[i][2 * i] = 1; //ÿ�еĵ�0�к����һ�ж���1
			for (j = 1; j < 2 * i; ++j) //��ĳһ�е�1�е���2i-1��(�����ڶ���)��ֵ
			{
				if (j == 1) //��ǰ�е�һ��ֵΪ��һ�е�0��+��1��
					num[i][j] = num[i - 1][j - 1] + num[i - 1][j];
				else //������Ϊ�������ĺ�(���Ͻ�j-2�����Ϸ�j-1�����Ͻ�j)
					num[i][j] = num[i - 1][j - 2] + num[i - 1][j - 1] + num[i - 1][j];
			}
		}
		for (i = 1; i < m - 1; ++i) //�ڵ�n���ҵ�һ��ż����λ��
		{
			if (!((num[n - 1][i]) & 1) && num[n - 1][i] != 0) //����ǿ��Ա�2�����Ҳ���0˵����ż����������λ��
			{
				cout << i + 1 << endl;
				break;
			}
		}
		if (i == m) //�Ҳ�������-1
			cout << -1 << endl;
	}
	return 0;
}