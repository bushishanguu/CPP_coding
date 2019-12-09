#define _CRT_SECURE_NO_WARNINGS 1


class Solution {
public:
	int jumpFloorII(int number) {
		if (number <= 0)
			return 0;
		int n = 1;
		for (int i = 1; i<number; i++)
			n *= 2;
		return n;
	}
};