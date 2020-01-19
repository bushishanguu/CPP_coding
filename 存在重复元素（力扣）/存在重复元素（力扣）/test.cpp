#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		if (nums.size() == 0) //先判断
		{
			return false;
		}
		sort(nums.begin(), nums.end());//再排序
		for (int i = 0; i < nums.size() - 1; i++)
		{
			if (nums[i] == nums[i + 1]) //逐一进行比较
			{
				return true;
			}
		}
		return false;
	}
};