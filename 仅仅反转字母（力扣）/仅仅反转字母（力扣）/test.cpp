#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	string reverseOnlyLetters(string S) {//双指针法  一个在前 一个在后
		int left = 0;
		int right = S.size() - 1;
		while (left < right)
		{
			while (left < right && !isalpha(S[left]))//left右移直到遇到字母才停下
			{
				++left;
			}

			while (right > left && !isalpha(S[right]))//right左移直到遇到字母才停下
			{
				--right;
			}

			swap(S[left++], S[right--]);//交换两个位置的字母，同时右移left，左移right
		}
		return S;
	}
};