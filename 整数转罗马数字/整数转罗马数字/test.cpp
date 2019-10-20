#define _CRT_SECURE_NO_WARNINGS 1
char * intToRoman(int num){
	char * ret = NULL;
	if (num <= 0 || num > 3999) return ret;
	ret = (char *)malloc(sizeof(char)* 16);
	if (ret == NULL) {
		printf("ÉêÇëÄÚ´æ³ö´í");
		exit(0);
	}
	ret[15] = 0; // memset(ret, 0, 16);

	char Rome[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
	char i = 14, j = 0, m = 0;

	while (num) {
		m = num % 10;
		num /= 10;
		while (1) {
			if (m == 9) { ret[i--] = Rome[j + 2]; m = 1; }
			else if (m == 8) { ret[i--] = Rome[j]; m--; }
			else if (m == 7) { ret[i--] = Rome[j]; m--; }
			else if (m == 6) { ret[i--] = Rome[j]; m--; }
			else if (m == 5) { ret[i--] = Rome[j + 1]; break; }
			else if (m == 4) { ret[i--] = Rome[j + 1]; m = 1; }
			else if (m == 3) { ret[i--] = Rome[j]; m--; }
			else if (m == 2) { ret[i--] = Rome[j]; m--; }
			else if (m == 1) { ret[i--] = Rome[j]; break; }
			else break;
		}
		j += 2;
	}
	return (ret + i + 1);
}
