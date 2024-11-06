#include<iostream>

using namespace std;
int arr[1001][1001];
int visited[1001];
int cnt;
int n, m;
void dfs(int node)
{
	if (visited[node] == 1)
		return;
	visited[node] = 1;
	for (int i = 1; i <= n; i++) {
		if (arr[node][i] == 1&&!visited[i]) {
			dfs(i);
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
			cnt++;
		}
	}
	cout << cnt;
}