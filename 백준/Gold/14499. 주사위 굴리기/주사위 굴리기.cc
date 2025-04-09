#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[21][21];
int dice[6] = { 0,0,0,0,0,0 };//위0 북1 동2 서3 남4 밑5
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, x, y, k;
	cin >> n >> m >> x >> y >> k; //x가 행 y가 열
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	vector<int> move(k);
	for (int i = 0; i < k; i++) {
		cin >> move[i];
	}
	for (int i = 0; i < move.size(); i++) {
		if (move[i] == 1) { //동
			if (y+1 >= m) 
				continue;
			y = y + 1;
			int temp = dice[5];
			dice[5] = dice[2];
			dice[2] = dice[0];
			dice[0] = dice[3];
			dice[3] = temp;
			if (arr[x][y] == 0) {
				arr[x][y] = dice[5];
			}
			else {
				dice[5] = arr[x][y];
				arr[x][y] = 0;
			}
			cout << dice[0]<<"\n";
		}
		else if (move[i] == 2) { //서
			if (y - 1 < 0)
				continue;
			y = y - 1;
			int temp = dice[5];
			dice[5] = dice[3];
			dice[3] = dice[0];
			dice[0] = dice[2];
			dice[2] = temp;
			if (arr[x][y] == 0) {
				arr[x][y] = dice[5];
			}
			else {
				dice[5] = arr[x][y];
				arr[x][y] = 0;
			}
			cout << dice[0] << "\n";
		}
		else if (move[i] == 3) { //북
			if (x - 1 < 0)
				continue;
			x = x - 1;
			int temp = dice[5];
			dice[5] = dice[1];
			dice[1] = dice[0];
			dice[0] = dice[4];
			dice[4] = temp;
			if (arr[x][y] == 0) {
				arr[x][y] = dice[5];
			}
			else {
				dice[5] = arr[x][y];
				arr[x][y] = 0;
			}
			cout << dice[0] << "\n";
		}
		else if (move[i] == 4) {
			if (x + 1 >= n)
				continue;
			x = x + 1;
			int temp = dice[5];
			dice[5] = dice[4];
			dice[4] = dice[0];
			dice[0] = dice[1];
			dice[1] = temp;
			if (arr[x][y] == 0) {
				arr[x][y] = dice[5];
			}
			else {
				dice[5] = arr[x][y];
				arr[x][y] = 0;
			}
			cout << dice[0] << "\n";
		}
	}
}