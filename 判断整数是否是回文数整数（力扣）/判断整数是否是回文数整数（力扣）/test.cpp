#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	bool isPalindrome(int x) {
		if (x == 0)
		{
			return true;
		}
		if (x<0)
		{
			return false;
		}
		double n = 0, y = x;
		while (x > 0){
			n *= 10;
			n += x % 10;
			x /= 10;
		}
		if (n == y)
			return true;
		else
			return false;
	}
};
