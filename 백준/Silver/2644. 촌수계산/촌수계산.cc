#include<iostream>

using namespace std;
int n;
int t1, t2;
int m;
int arr[101][101];
int visited[101];
int cnt = 0;
int result = -1;
void dfs(int start, int end)
{
	if (start == t2) {
		result = cnt;
		return;
	}
	visited[start] = 1;
	cnt++;
	for (int i = 1; i <= end; i++) {
		if (visited[i] == 1)
			continue;
		if (arr[start][i] == 0)
			continue;
		dfs(i, end);
	}
	cnt--;
}
int main()
{
	cin >> n;
	cin >> t1 >> t2;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	dfs(t1, t2);
	cout << result;
}