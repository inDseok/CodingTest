#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int arr[1001][1001];
int tomato[1001][1001];
bool visited[1001][1001];
int result = 0;
int minus_cnt = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m,n;
	cin >>m >> n;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				q.push({ i,j });
				visited[i][j] = true;
				minus_cnt++;
			}
			if(arr[i][j]==-1)
				minus_cnt++;
			tomato[i][j] = 0;
		}
	}
	while (!q.empty()) {
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_y = cur_y + dy[i];
			int next_x = cur_x + dx[i];
			if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= m)
				continue;
			if (arr[next_y][next_x] == -1)
				continue;
			if (visited[next_y][next_x])
				continue;
			tomato[next_y][next_x] = tomato[cur_y][cur_x] + 1;
			visited[next_y][next_x] = true;
			if (tomato[next_y][next_x] > result)
				result = tomato[next_y][next_x];
			q.push({ next_y,next_x });
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tomato[i][j] == 0)
				minus_cnt--;
		}
	}
	if (minus_cnt == 0)
		cout << result;
	else
		cout << "-1";
	return 0;
}
