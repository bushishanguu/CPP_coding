#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) {//˫ָ�뷨��
		int begin = 0;
		int end = A.size() - 1;
		while (begin < end)
		{
			while (A[begin] % 2 == 0 && begin< end)    //��ͷ����
				begin++;
			while (A[end] % 2 != 0 && begin< end)   //��β����  ���Ѿ��ĺ���ż���Ͳ�������
				end--;
			if (begin < end)  //û�źõľͽ��н���
			{
				swap(A[begin], A[end]);
			}
		}
		return A;
	}
};