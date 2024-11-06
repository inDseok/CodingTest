#include<iostream>

using namespace std;
int comb[1001][1001];
int main()
{
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			if (i >= j) {
				if (j == 1) {
					comb[i][j] = i;
				}
				if (i == j || j==0) {
					comb[i][j] = 1;
				}
				else
					comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % 10007;
			}
		}
	}
	int result = comb[N][K] ;
	cout << result;
}