#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<string.h>
using namespace std;
//所要的十进制转B进制的函数
void shift(int B, int before)
{
	char B_num[B];
	if (B<10){ for (int i = 0; i<B; i++)B_num[i] = i + 48; }
	else
	{
		for (int i = 0; i<B; i++)B_num[i] = i + 48;
		for (int j = 10; j<B; j++)B_num[j] = 'A' + j - 10;
	}//定义好大于10的各个位置表示符号
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
	cout << "转换后的数字是:" << endl;
	for (int i = result.length() - 1; i >= 0; i--)cout << result[i];
	cout << endl;
}

int main()
{
L:int num; int B;
	cout << "要将十进制数转换为几进制的数?" << endl;
	cin >> B;
	cout << "请输入要转换的十进制数据" << endl;
	cin >> num;
	shift(B, num);
	goto L;
	return 0;
}
