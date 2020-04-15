#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int main() {
	int n, m, k;
	while (cin >> n >> m >> k) {
		vector<vector<int>>table(n + 1, vector<int>(m + 1));
		vector<vector<double>>P(n + 1, vector<double>(m + 1));

		int x, y;
		for (int i = 0; i < k; ++i) {
			cin >> x >> y;
			table[x][y] = 1;
		}

		P[1][1] = 1.0; //������Ϊ1
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++){
				//�������
				if (!(i == 1 && j == 1)) {
					P[i][j] = P[i - 1][j] * (j == m ? 1 : 0.5) +
						P[i][j - 1] * (i == n ? 1 : 0.5);

					//�߽��ʱ�򣬸���Ϊ1
					if (table[i][j] == 1) {
						//����õ���Ģ����������Ϊ0
						P[i][j] = 0;
					}
				}
			}
		}

		//fixed ���õ��Ǹ�ʽ��setprccision(2)��˼�Ǳ�����λС��
		cout << fixed << setprecision(2) << P[n][m] << endl;
		printf("%.2f", P[n][m]);
	}

	return 0;
}