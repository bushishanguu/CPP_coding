#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	bool isHappy(int n) {

		for (int i = 0; i < 8; i++) { //ֻ��Ҫ�ж�8��ѭ��
			int temp = 0;
			while (n > 0) {
				temp += (n % 10) * (n % 10);
				n /= 10;
			}
			n = temp;
			if (n == 1)
				return true;
		}
		return false;
	}
};