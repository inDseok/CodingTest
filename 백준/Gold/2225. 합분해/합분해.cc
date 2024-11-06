#include<iostream>

using namespace std;
int n, k;
int result = 0;
int arr[201][201];
int main()
{
	cin >> n >> k;
	arr[0][0] = 1;
	for (int i = 1; i <= k; i++) {
		arr[i][0] = 1;
		for (int j = 1; j <= n; j++) {
			arr[i][j] += (arr[i - 1][j] + arr[i][j - 1]) % 1000000000;
		}
	}
	cout << arr[k][n];
}