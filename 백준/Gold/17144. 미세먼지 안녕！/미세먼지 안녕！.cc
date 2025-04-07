#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int arr[51][51];
int r,c,t;
int vacuum;//청소기 아래 행
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
void spread() {
	vector<vector<int>> temp (r, vector<int>(c, 0));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 0)
				continue;
			int dust = arr[i][j] / 5;
			int sum = 0;
			for (int k = 0; k < 4; k++) {
				int yy = i + dy[k];
				int xx = j + dx[k];
				if (yy < 0 || yy >= r || xx < 0 || xx >= c)
					continue;
				if (arr[yy][xx]==-1)
					continue;
				temp[yy][xx] += dust;
				sum += dust;
			}
			temp[i][j] -= sum;
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			arr[i][j] += temp[i][j];
		}
	}
}
void move() {
	// 위쪽 공기청정기: 반시계 방향
	int top = vacuum - 1;

	// 위쪽: 아래로 당기기
	for (int i = top - 1; i > 0; i--)
		arr[i][0] = arr[i - 1][0];
	// 위쪽: 왼쪽으로 밀기
	for (int j = 0; j < c - 1; j++)
		arr[0][j] = arr[0][j + 1];
	// 위쪽: 위로 밀기
	for (int i = 0; i < top; i++)
		arr[i][c - 1] = arr[i + 1][c - 1];
	// 위쪽: 오른쪽에서 왼쪽으로
	for (int j = c - 1; j > 1; j--)
		arr[top][j] = arr[top][j - 1];
	arr[top][1] = 0;

	// 아래쪽 공기청정기: 시계 방향
	int bottom = vacuum;

	// 아래쪽: 위로 당기기
	for (int i = bottom + 1; i < r - 1; i++)
		arr[i][0] = arr[i + 1][0];
	// 아래쪽: 왼쪽으로 밀기
	for (int j = 0; j < c - 1; j++)
		arr[r - 1][j] = arr[r - 1][j + 1];
	// 아래쪽: 아래로 밀기
	for (int i = r - 1; i > bottom; i--)
		arr[i][c - 1] = arr[i - 1][c - 1];
	// 아래쪽: 오른쪽에서 왼쪽으로
	for (int j = c - 1; j > 1; j--)
		arr[bottom][j] = arr[bottom][j - 1];
	arr[bottom][1] = 0;

	// 청정기 위치 고정
	arr[top][0] = -1;
	arr[bottom][0] = -1;
}

int main() {

	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1)
				vacuum = i;
		}
	}
	while (t--) {
		spread();
		move();
	}
	int sum = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] > 0)
				sum += arr[i][j];
		}
	}
	cout << sum;
	return 0;
}