#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int *dp= new int[1000001];
int madeone(int N)
{
	dp[0] = 0;
	dp[1] = 0;
	for (int i = 2; i <= N ; ++i) {
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0)
		dp[i] = min(dp[i], dp[i / 3] + 1);
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
	}
	return dp[N];
}

int main() {
	int N;
	cin >> N;
	cout<<madeone(N);
	return 0;
}