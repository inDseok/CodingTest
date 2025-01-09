#include<iostream>
#include <vector>
#include<algorithm>
#include<queue>
using namespace std;
int arr[1001][1001];
int visited[1001][1001][2];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int n, m;
struct pos {
	int y;
	int x;
	int wall;
};
bool chk(int yy, int xx) {
	return yy >= 0 && yy < n && xx >= 0 && xx < m;
}
int bfs() {
	queue<pos> q;
	q.push({ 0,0,0 });
	visited[0][0][0] = 1;
	while (!q.empty()) {
		int cury = q.front().y;
		int curx = q.front().x;
		int curbroken = q.front().wall;
		q.pop();
		if (cury == n - 1 && curx == m - 1) {
			return visited[cury][curx][curbroken];
		}
		for (int i = 0; i < 4; i++) {
			int yy = cury + dy[i];
			int xx = curx + dx[i];
			if (!chk(yy, xx))
				continue;
			if (arr[yy][xx] == 1 && curbroken == 0) { //벽을 만났는데 부순적 없음
				visited[yy][xx][1] = visited[cury][curx][curbroken] + 1;
				q.push({ yy,xx,1 });
			}
			else if (arr[yy][xx] == 0 && visited[yy][xx][curbroken] == 0) {
				visited[yy][xx][curbroken] = visited[cury][curx][curbroken] + 1;
				q.push({ yy,xx ,curbroken });
			}
		}
	}
	return -1;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < m; j++) {
				arr[i][j] = s[j] - '0';
			}
	}
	cout << bfs();
	return 0;
}