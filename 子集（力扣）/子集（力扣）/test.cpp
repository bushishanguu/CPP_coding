#define _CRT_SECURE_NO_WARNINGS 1
class Solution
{
public:
	vector<vector<int>> subsets(vector<int> &nums)//位运算，对数字统一进行编码
	{
		int total = 1 << nums.size();
		vector<vector<int>> result(total);
		for (int i = 0; i < total; i++)
		for (int j = i, k = 0; j; j >>= 1, k++)
		if (j & 1 == 1)
			result[i].push_back(nums[k]);
		return result;
	}
};