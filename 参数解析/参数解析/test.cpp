#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	int i = 0;
	int count = 1;//���ȸ��ݿո��˫�����жϲ�����������ʼֵΪ1
	while (getline(cin, str))
	{
		for (i = 0; i<str.size(); ++i)
		{
			if (str[i] == '"')//����˫����ֱ������������һ����˫����
			{
				do
				{
					i++;
				} while (str[i] != '"');
			}
			else if (str[i] == ' ')//�����ո����������+1
				++count;
		}
		cout << count << endl;
		int temp = 0;//����ֽ��Ĳ���������һ����־���жϵ�ǰ�Ƿ���˫������
		for (i = 0; i < str.size(); ++i)
		{
			if (str[i] == '"')
				temp ^= 1;

			if (str[i] != ' '&&str[i] != '"')//���ǿո��˫����ֱ�Ӵ�ӡ
				cout << str[i];
			else if (str[i] == ' ')
			{
				if (temp)
					cout << str[i];//˫�����еĿո��ӡ
				else
					cout << endl;//˫������Ŀո��û��д���
			}
		}
	}
	return 0;
}
