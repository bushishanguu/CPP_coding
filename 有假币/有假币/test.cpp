#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

/*�ټ������Ӿ����뵽���ķ����Ƿֳ����ݣ�
*�Ƚ����е����ݣ�����������ٱ�������Ƿݣ���������ٱ��ڵ����ݣ�ֱ��n%3
*���������ǲ��ܾ��ֵ������
*��Ϊ�Ƿ�3�ݣ�����ֻ���ܶ���1������
*���ǿ�������������ٱ�������һ��������Ƿ�Ϊn%3+1
*/

int main()
{
	int n;
	while (cin >> n)
	{
		if (0 == n)
			break;
		int count = 0;
		while (n >= 2)
		{
			if (n % 3)
				n = n / 3 + 1;
			else
				n = n / 3;
			++count;
		}
		cout << count << endl;
	}
	return 0;
}