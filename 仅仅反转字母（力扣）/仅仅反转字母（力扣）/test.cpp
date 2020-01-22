#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	string reverseOnlyLetters(string S) {//˫ָ�뷨  һ����ǰ һ���ں�
		int left = 0;
		int right = S.size() - 1;
		while (left < right)
		{
			while (left < right && !isalpha(S[left]))//left����ֱ��������ĸ��ͣ��
			{
				++left;
			}

			while (right > left && !isalpha(S[right]))//right����ֱ��������ĸ��ͣ��
			{
				--right;
			}

			swap(S[left++], S[right--]);//��������λ�õ���ĸ��ͬʱ����left������right
		}
		return S;
	}
};