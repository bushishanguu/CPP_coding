#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {

		// ���ҵ��򷵻ص�ǰ��λ��
		// ���Ҳ����򷵻�leftָ���λ��
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