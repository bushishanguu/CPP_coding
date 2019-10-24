#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int length = s.length();

		if (!length)
			return 0;
		if (length == 1)
			return 1;

		int p = 0, mlen = 1;

		for (int end = 1; end<length; end++){
			for (int aim = p; aim<end; aim++){

				if (s[aim] == s[end]){

					p = aim + 1;

					if (mlen<(end - aim))
						mlen = end - aim;
					break;
				}
			}

			if (mlen<end - p + 1)
				mlen = end - p + 1;
		}
		return mlen;
	}
};