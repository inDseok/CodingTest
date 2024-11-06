#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	int pay[1001][3]={0, }; //집 칠하는 비용
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> pay[i][j];
		}
	}
	int dp[1001][3] = {0,}; //i번째 집을 j로 칠했을 때 1~j번 집을 칠하는 최소 비용
	/* 다 더해보고 최소 비용 구하기 */

	for (int i = 1; i <= N; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + pay[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + pay[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + pay[i][2];
	}
	cout << min({ dp[N][0], dp[N][1], dp[N][2] }) << '\n';
	return 0;
}