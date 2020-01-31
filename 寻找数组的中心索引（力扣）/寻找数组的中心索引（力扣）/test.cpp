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
			RSum += nums[i];//�ұߵĺ͵���1�����һ��Ԫ�صĺ�
		if (LSum == RSum)//Ԥ�жϣ������� ֱ�ӷ����±�
			return 0;
		for (int i = 1; i < nums.size(); i++){
			RSum -= nums[i], LSum += nums[i - 1];//�������
			if (RSum == LSum)
				return i;
		}
		return -1;
	}
};

