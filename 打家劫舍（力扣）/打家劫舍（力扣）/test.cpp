#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	int rob(vector<int>& nums)
	{
		int sumOdd = 0;
		int sumEven = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			if (i % 2 == 0)
			{
				sumEven += nums[i];
				sumEven = max(sumOdd, sumEven);
			}
			else
			{
				sumOdd += nums[i];
				sumOdd = max(sumOdd, sumEven);
			}
		}
		return max(sumOdd, sumEven);
	}
};
