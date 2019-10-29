#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		vector<int>::size_type nSize = nums.size();
		if (nSize <= 1)
			return nSize;

		vector<int>::size_type p = 1;
		for (vector<int>::size_type i = 1; i < nSize; ++i) {
			if (nums[i] != nums[i - 1])
				nums[p++] = nums[i];
		}

		return p;
	}
};

