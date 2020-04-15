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

		P[1][1] = 1.0; //起点概率为1
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++){
				//跳过起点
				if (!(i == 1 && j == 1)) {
					P[i][j] = P[i - 1][j] * (j == m ? 1 : 0.5) +
						P[i][j - 1] * (i == n ? 1 : 0.5);

					//边界的时候，概率为1
					if (table[i][j] == 1) {
						//如果该点有蘑菇，概率置为0
						P[i][j] = 0;
					}
				}
			}
		}

		//fixed 设置的是格式，setprccision(2)意思是保留两位小数
		cout << fixed << setprecision(2) << P[n][m] << endl;
		printf("%.2f", P[n][m]);
	}

	return 0;
}