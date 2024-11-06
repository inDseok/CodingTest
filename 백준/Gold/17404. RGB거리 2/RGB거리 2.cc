#include<iostream>
#include <algorithm>
using namespace std;
int n;
int arr[1001][3] = { 0, };
int main()
{
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	int dp[1001][3]={0,};
	int result=100000;
	for (int k = 0; k < 3; k++) {
		for (int j = 0; j < 3; j++) {
			if (j == k)
				dp[1][j] = arr[1][j];
			else
				dp[1][j] = 1000000;
		}
		for (int i = 2; i <= n; i++) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
		}
		for (int i = 0; i < 3; i++) {
			if (i == k)
				continue;
			else
				result = min(result,dp[n][i]);
		}
	}
	cout << result<<"\n";
	return 0;
}