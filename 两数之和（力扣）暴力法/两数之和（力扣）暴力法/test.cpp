#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {//±©Á¦·¨
		int num = 0;
		vector<int> a;
		for (int i = 0; i < nums.size(); ++i)
		{
			num = target - nums[i];
			for (int j = i + 1; j < nums.size(); ++j)
			{
				if (num == nums[j])
				{
					a.push_back(i);
					a.push_back(j);
					return a;
				}
			}
		}
		return a;
	}
};