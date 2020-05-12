#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	int rectCover(int number) {
		if (number <= 0)
			return 0;
		if (number == 1)
			return 1;
		if (number == 2)
			return 2;
		int a = 1;
		int b = 2;
		int sum;
		for (int i = 2; i<number; i++)
		{
			sum = a + b;
			a = b;
			b = sum;
		}
		return sum;

	}
};