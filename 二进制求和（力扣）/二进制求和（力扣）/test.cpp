#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	string addBinary(string a, string b) {//��ĩβ��ʼ��λ���
		int a1 = a.size();
		int b1 = b.size();
		while (a1<b1)//��֤�����Է���������ȣ��������ȣ�����ǰ���0����
		{
			a = '0' + a;
			++a1;
		}
		while (a1>b1)
		{
			b = '0' + b;
			++b1;
		}
		for (int i = a.size() - 1; i>0; --i)//��λ������� ��2��һ
		{
			a[i] = a[i] - '0' + b[i];
			if (a[i] >= '2')
			{
				a[i] = (a[i] - '0') % 2 + '0';
				a[i - 1] = a[i - 1] + 1;
			}
		}
		a[0] = a[0] - '0' + b[0];//��λ��������
		if (a[0] >= '2')
		{
			a[0] = (a[0] - '0') % 2 + '0';
			a = '1' + a;
		}
		return a;

	}
};