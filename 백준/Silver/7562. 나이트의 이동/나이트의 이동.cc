#include<iostream>
#include <cstring>
#include<queue>
using namespace std;
int k;
int n;
int arr[301][301] = { 0, };
int visited[301][301] = { 0, };
int s_y, s_x,e_y,e_x;
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

int cnt;
void bfs(int a, int b)
{
	queue<pair<int, int>> q;
	visited[a][b] = 0;
	q.push(make_pair(a, b));
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (y == e_y && x == e_x) {
			cnt = visited[y][x];
			return;
		}
		for (int i = 0; i < 8; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx >= 0 && yy >= 0 && xx < n && yy < n) {
				if (!visited[yy][xx]) {
					q.push(make_pair(yy, xx));
					visited[yy][xx] =visited[y][x]+ 1;
				}
			}
		}
	}
}
int main()
{
	cin >> k;
	while (k--)
	{
		cin >> n;
		cin >> s_y >> s_x;
		cin >> e_y >> e_x;
		arr[s_y][s_x] = 1;
		arr[e_y][e_x] = -1;
		bfs(s_y, s_x);
		cout << cnt << "\n";
		memset(arr, 0, sizeof(arr));
		memset(visited, 0, sizeof(visited));
	}
}