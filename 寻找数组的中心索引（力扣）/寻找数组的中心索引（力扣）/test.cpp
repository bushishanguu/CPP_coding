#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return -1;
		}
		int LSum = 0;
		int RSum = 0;

		for (int i = 1; i < nums.size(); i++)
			RSum += nums[i];//右边的和等于1到最后一个元素的和
		if (LSum == RSum)//预判断，如果相等 直接返回下标
			return 0;
		for (int i = 1; i < nums.size(); i++){
			RSum -= nums[i], LSum += nums[i - 1];//右退左进
			if (RSum == LSum)
				return i;
		}
		return -1;
	}
};

