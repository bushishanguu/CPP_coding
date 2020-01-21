#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	bool isLongPressedName(string name, string typed) {
		//����name���ַ������������ʱ��ͬʱ++�� ���߲���ʱ��typed���ơ�
		if (name == typed) //�Ƚ���Ԥ�ж�  
		{
			return true;
		}
		if (name.size() > typed.size())
		{
			return false;
		}
		int i = 0;
		int j = 0;
		while (i < name.size() && j < typed.size())
		{
			if (name[i] == typed[j])//����name���ַ������������ʱ��ͬʱ++��
			{
				++i;
				++j;
			}
			else//���߲���ʱ��typed����
			{
				++j;
			}
		}
		while (j < typed.size())//��nameɨ����֮�󣬰�typedʣ���β�����ж�һ�¡�    
		{
			if (name[i - 1] != typed[j])   return false;
			else
				++j;
		}
		return i == name.size();
	}
};