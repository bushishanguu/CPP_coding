#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:

	string countAndSay(int n) {
		string ret = "1";
		string tmp;
		int cnt = 0;
		if (n == 1) return ret;


		for (int i = 1; i < n; ++i) {
			tmp.clear();
			char ch = ret[0];
			cnt = 1;
			for (int j = 1; j < ret.size(); ++j) {
				if (ret[j] == ch) {
					// ͳ����ͬ��������
					cnt++;
				}
				else {
					// ��¼����������
					tmp.append(to_string(cnt));
					tmp.append(&ch, 1);
					// ��ʼ��״̬,����ͳ��
					ch = ret[j];
					cnt = 1;
				}
			}
			// ��¼���һ��ͳ��
			tmp.append(to_string(cnt));
			tmp.append(&ch, 1);
			ret = tmp;
		}
		return ret;
	}

