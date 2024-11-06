#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	int N, M;
	int dp[31][31];
	while (T--){
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (i <= j) {
					if (i == 1) {
						dp[i][j] = j;
					}
					else if (j == i) {
						dp[i][j] = 1;
					}
					else {
						dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
					}
				}
			}
		}
		cout << dp[N][M] << endl;
	}
}