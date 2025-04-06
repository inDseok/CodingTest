#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int arr[500][500];
int n;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };
int cr, cc;
int length = 1;
int cnt = 0; //횟수
int bigcnt = 0; //방향 전환 횟수
int dir = 0;
//좌하우상
int ry[4][10] = { { -1,1,-1,1,-1,1,-2,2,0,0 },
				  { 0,0,1,1,2,2,1,1,3,2 },
				  { -1,1,-1,1,-1,1,-2,2,0,0 },
				  { 0,0,-1,-1,-2,-2,-1,-1,-3,-2 } };
int rx[4][10] = { { 0,0,-1,-1,-2,-2,-1,-1,-3,-2 },
				 { -1,1,-1,1,-1,1,-2,2,0,0 },
				 { 0,0,1,1,2,2,1,1,3,2 },
				 { -1,1,-1,1,-1,1,-2,2,0,0 } };

vector<int> percent = { 1,1,7,7,10,10,2,2,5 };
int result=0;
bool is_range(int ny, int nx) {
	return (nx >= 0 && nx < n&& ny >= 0 && ny < n);
}
void move(int sy, int sx, int ey, int ex, int dir) {
	int mo = arr[ey][ex];
	arr[ey][ex] = 0;
	int sum = mo;
	for (int i = 0; i < 9; i++) {
		int ny = sy + ry[dir][i];
		int nx = sx + rx[dir][i];
		int spread = mo * (0.01 * percent[i]);
		sum -= spread;
		if(is_range(ny,nx)){
			arr[ny][nx] += spread;
		}
		else {
			result += spread;
		}
	}
	//알파 구하기
	int ny = sy + ry[dir][9];
	int nx = sx + rx[dir][9];
	if (is_range(ny, nx)) {
		arr[ny][nx] += sum;
	}
	else {
		result += sum;
	}
}
void tornado() {
	cr = n / 2;
	cc = n / 2;
	while (1) {
		if (dir >= 4)
			dir = 0;
		int ny = cr + dy[dir];
		int nx = cc + dx[dir];
		if (!is_range(ny,nx))
			break;
		if (arr[ny][nx] > 0)
			move(cr, cc, ny, nx, dir);
		cnt++;
		if (length == cnt) {
			cnt = 0;
			dir++;
			bigcnt++;
		}
		if (bigcnt == 2) {
			length++;
			bigcnt = 0;
		}
		cr = ny;
		cc = nx;
	}
}
int main() {
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			sum += arr[i][j];
		}
	}
	tornado();
	int sum2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum2 += arr[i][j];
		}
	}
	cout << sum - sum2;
	return 0;
}