#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	const long MAX = (1 << 31) - 1, MIN = (-1 << 31);
	int reverse(int x) {
		if (x / 10 == 0) return x;
		long y = 0;
		while (x)
		{
			y *= 10;
			if (y > MAX || y < MIN)
				return 0;
			y += x % 10;
			x /= 10;
		}
		return y;
	}
};
