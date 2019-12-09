#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		if£¨array.empty()){
			return -1;
		}
		int curMax = array[0];
		int Max = array[0];
		for (int i = 1; i<array.size(); i++)
		{
			curMax = (curMax>0) ? curMax + array[i] : array[i];
			Max = (curMax<Max) ? Max : curMax;
		}
		return Max;
	}
};