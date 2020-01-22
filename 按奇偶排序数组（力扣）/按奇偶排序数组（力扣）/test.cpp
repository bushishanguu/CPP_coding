#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) {//双指针法。
		int begin = 0;
		int end = A.size() - 1;
		while (begin < end)
		{
			while (A[begin] % 2 == 0 && begin< end)    //从头遍历
				begin++;
			while (A[end] % 2 != 0 && begin< end)   //从尾遍历  若已经拍好奇偶数就不用再排
				end--;
			if (begin < end)  //没排好的就进行交换
			{
				swap(A[begin], A[end]);
			}
		}
		return A;
	}
};