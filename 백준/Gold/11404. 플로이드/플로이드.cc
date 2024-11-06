#include<iostream>
#include<algorithm>
using namespace std;
#define INF 100000000
int n, m;
int arr[101][101];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				arr[i][j] = 0;
			else
				arr[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		arr[x][y] = min(arr[x][y],d);
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == INF) {
				cout << "0"<<" ";
			}
			else
				cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}