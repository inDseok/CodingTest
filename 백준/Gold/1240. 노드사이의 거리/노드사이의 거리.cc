#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n, m;
int visited[1001];
int x, y, d;
vector<pair<int, int>> v[1001];
int bfs(int a, int b)
{
	queue<pair<int, int>> q;
	visited[a] = 1;
	q.push(make_pair(a, 0));
	while (!q.empty()) {
		int c_node = q.front().first;
		int c_dist = q.front().second;
		q.pop();
		if (c_node == b)
			return c_dist;
		for (int i = 0; i < v[c_node].size(); i++) {
			int n_node = v[c_node][i].first;
			int n_dist = v[c_node][i].second;
			if (!visited[n_node]) {
				visited[n_node] = 1;
				q.push(make_pair(n_node, (c_dist + n_dist)));
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y >> d;
		v[x].push_back(make_pair(y, d));
		v[y].push_back(make_pair(x, d));
	}
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		memset(visited, 0, sizeof(visited));
		cout << bfs(x,y) << "\n";
	}
}