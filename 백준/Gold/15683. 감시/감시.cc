#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<pair<int, int>> cctv;
vector<vector<int>> board(8, vector<int>(8));
int n, m;
int result = 99999;
void update(pair<int, int> cur, int dir) {
	dir %= 4;
	while (1) {
		int yy = cur.first + dy[dir];
		int xx = cur.second + dx[dir];
		cur.first = yy;
		cur.second = xx;
		if (xx < 0 || xx >= m || yy<0 || yy>=n)
			break;
		if (board[yy][xx] == 6)
			break;
		if (board[yy][xx] != 0)
			continue;
		board[yy][xx] = -1;
	}
}
void dfs(int idx) {
	if (idx == cctv.size()) {
		int temp = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 0)
					temp++;
			}
		}
		result = min(result, temp);
		return;
	}
	auto cur = cctv[idx];
	vector<vector<int>> v;
	for (int dir = 0; dir < 4; dir++) {
		v = board;
		switch (board[cur.first][cur.second])
		{
		case 1:
			update(cur, dir);
			break;
		case 2:
			update(cur, dir);
			update(cur, dir+2);
			break;
		case 3:
			update(cur, dir);
			update(cur, dir+1);
			break;
		case 4:
			update(cur, dir);
			update(cur, dir+1);
			update(cur, dir+2);
			break;
		case 5:
			update(cur, dir);
			update(cur, dir+1);
			update(cur, dir+2);
			update(cur, dir+3);
			break;
		}
		dfs(idx + 1);
		board = v;
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] != 0 && board[i][j] != 6)
				cctv.push_back({ i,j });
		}
	}
	dfs(0);
	cout << result;
}