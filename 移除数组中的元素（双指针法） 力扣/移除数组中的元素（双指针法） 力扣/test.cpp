#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {//����ָ�뷨
		int i = 0;
		int j = 0;
		for (j = 0; j<nums.size(); j++)
		{
			if (nums[j] != val)//�ҳ����ǵ�����
			{
				nums[i] = nums[j];
				i++;
			}
		}
		return i;
	}
};
