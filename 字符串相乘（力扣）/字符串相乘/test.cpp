#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0")
			return "0";
		int l1 = num1.length() - 1;
		int l2 = num2.length() - 1;
		vector<int> mul(l1 + l2 + 2);

		for (int i = l1; i >= 0; i--)
		for (int j = l2; j >= 0; j--)
		{
			int res = (num1[i] - '0')*(num2[j] - '0');//乘积
			res = res + mul[i + j + 1];//低位相加
			mul[i + j] = mul[i + j] + res / 10;//高位
			mul[i + j + 1] = res % 10;//低位  
		}
		int i = 0;
		while (mul[i] == 0 && i<l1 + l2 + 1)
			i++;
		string multi;
		for (; i<l1 + l2 + 2; i++)
			multi.append(to_string(mul[i]));
		return multi;
	}
};