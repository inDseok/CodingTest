#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
	int N;
	cin >> N;
	int day[100];
	int pay[100];
	int dp[100] = { 0, };
	for (int i = 1; i <= N; i++) {
		cin >> day[i] >> pay[i];
	}
	int days;
	for (int i = N; i > 0; i--) {
		days = i + day[i];
		if (days > N+1) {
			dp[i] = dp[i + 1];
		}
		else {
			dp[i] = max(dp[i + 1], dp[days] + pay[i]);
		}
	}
	cout << dp[1];
}