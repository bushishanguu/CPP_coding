#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	int firstUniqChar(string s) {
		int count[256] = { 0 };
		int size = s.size();
		for (int i = 0; i<size; ++i)
		{
			count[s[i]] = count[s[i]] + 1;
		}
		for (int i = 0; i<size; ++i)
		{
			if (count[s[i]] == 1)
				return i;
		}
		return -1;
	}
};