#include<iostream>
#include<algorithm>
using namespace std;
int n, m;
int arr[1001][1001];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			arr[i][j] = max(arr[i - 1][j], max(arr[i][j - 1], arr[i - 1][j - 1]))+arr[i][j];
		}
	}
	cout << arr[n][m];
 }