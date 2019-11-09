#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	bool isLetterOrNumber(char ch)
	{
		return (ch >= '0'&&ch <= '9')
			|| (ch >= 'a'&&ch <= 'z')
			|| (ch >= 'A'&&ch <= 'Z');
	}
	bool isPalindrome(string s) {
		for (auto& ch : s)
		{
			if (ch >= 'a'&&ch <= 'z')
				ch -= 32;
		}
		int begin = 0;
		int end = s.size() - 1;
		while (begin<end)
		{
			while (begin<end&&!isLetterOrNumber(s[begin]))
				++begin;
			while (begin<end&&!isLetterOrNumber(s[end]))
				--end;

			if (s[begin] != s[end])
			{
				return false;
			}
			else
			{
				++begin;
				--end;
			}
		}
		return true;
	}
};