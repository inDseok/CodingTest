#include<iostream>

using namespace std;
int n;
int arr[17][17];
int way[17][17][3];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	way[1][2][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j])
				continue;
			way[i][j][0] += way[i][j - 1][0] + way[i][j - 1][1];
			way[i][j][2] += way[i-1][j][1] + way[i-1][j][2];
			if (arr[i - 1][j] || arr[i][j - 1])
				continue;
			way[i][j][1] += way[i-1][j - 1][0] + way[i-1][j - 1][1]+way[i-1][j-1][2];
		}
	}
	cout << way[n][n][0] + way[n][n][1] + way[n][n][2];
}