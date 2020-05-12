#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.empty())
			return 0;
		int left = 0;
		int right = rotateArray.size() - 1;
		int mid = left;
		while (rotateArray[left] >= rotateArray[right])
		{
			if (right - left == 1)
			{
				mid = right;
				break;
			}
			mid = (left + right) / 2;
			if (rotateArray[left]<rotateArray[mid])
				left = mid;
			else if (rotateArray[mid]<rotateArray[right])
				right = mid;
			else
			{
				++left;
			}
		}
		return rotateArray[mid];
	}
};