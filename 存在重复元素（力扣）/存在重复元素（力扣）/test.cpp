#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		if (nums.size() == 0) //���ж�
		{
			return false;
		}
		sort(nums.begin(), nums.end());//������
		for (int i = 0; i < nums.size() - 1; i++)
		{
			if (nums[i] == nums[i + 1]) //��һ���бȽ�
			{
				return true;
			}
		}
		return false;
	}
};