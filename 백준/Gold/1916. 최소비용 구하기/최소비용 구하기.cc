#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, m;
int arr[1005][1005];
int a, b, d;
int dist[1005];
#define INF 100000000
void bfs(int x)
{
	priority_queue<pair<int, int>> pq;
	pq.push({0,x});
	while (!pq.empty())
	{
		int dist2 = pq.top().first;
		int current = pq.top().second;
		pq.pop();
		if (dist2 > dist[current])
			continue;
		for (int i = 1; i <= n; i++) {
			int v = i;
			int w = arr[current][i];
			if (w == INF)
				continue;
			if (dist2 + w < dist[v]) {
				dist[v] = dist2 + w;
				pq.push({ dist2 + w ,v});
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = INF;
		}
	}
	for (int i = 1; i <= n; i++) {
		arr[i][i] = 0;
		dist[i] = INF;
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> d;
		if (d < arr[a][b])
			arr[a][b] = d;
	}
	cin >> a >> b;
	dist[a] = 0;
	bfs(a);
	cout << dist[b]<<"\n";
}