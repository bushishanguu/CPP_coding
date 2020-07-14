#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	int jumpFloorII(int number) {
		if (number == 0 || number == 1)
		{
			return 1;
		}
		if (number == 2)
		{
			return 2;
		}
		int sum = 0;
		for (int i = 0; i<number; i++)
		{
			sum += jumpFloorII(i);
		}


		return sum;
	}
};