#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<string.h>
using namespace std;
//��Ҫ��ʮ����תB���Ƶĺ���
void shift(int B, int before)
{
	char B_num[B];
	if (B<10){ for (int i = 0; i<B; i++)B_num[i] = i + 48; }
	else
	{
		for (int i = 0; i<B; i++)B_num[i] = i + 48;
		for (int j = 10; j<B; j++)B_num[j] = 'A' + j - 10;
	}//����ô���10�ĸ���λ�ñ�ʾ����
	string result = "";
	int n; int m;
	while (before >= B)
	{
		n = before / B;
		m = before%B;
		result += B_num[m];
		before = n;
	}
	result += B_num[n];
	cout << "ת�����������:" << endl;
	for (int i = result.length() - 1; i >= 0; i--)cout << result[i];
	cout << endl;
}

int main()
{
L:int num; int B;
	cout << "Ҫ��ʮ������ת��Ϊ�����Ƶ���?" << endl;
	cin >> B;
	cout << "������Ҫת����ʮ��������" << endl;
	cin >> num;
	shift(B, num);
	goto L;
	return 0;
}
