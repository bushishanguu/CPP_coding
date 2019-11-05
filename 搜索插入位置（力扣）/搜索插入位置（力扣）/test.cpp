#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {

		// 若找到则返回当前的位置
		// 若找不到则返回left指针的位置
		int left = 0, right = nums.size() - 1, mid;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (nums[mid] > target) right = mid - 1;
			else if (nums[mid] < target) left = mid + 1;
			else return mid;
		}
		return left;
	}

};