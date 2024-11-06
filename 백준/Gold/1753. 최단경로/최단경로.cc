#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define INF 10000000
int v, e, k;
priority_queue<pair<int, int>> pq;
vector<pair<int, int>>vec[20001];
int d[20001];
int main()
{
	cin >> v >> e >> k;
	for (int i = 1; i <= e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		vec[u].push_back(make_pair(w, v));
	}
	for (int i = 1; i <= v; i++) {
		d[i] = INF;
	}
	d[k] = 0;
	pq.push({ 0,k });
	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int current = pq.top().second;
		pq.pop();
		if (d[current] < dist)
			continue;
		for (int i = 0; i < vec[current].size(); i++) {
			int next = vec[current][i].second;
			int next_dist = dist + vec[current][i].first;
			if (d[next] > next_dist) {
				d[next] = next_dist;
				pq.push({ -next_dist,next });
			}
		}
	}
	for (int i = 1; i <= v; i++) {
		if (d[i] != INF) {
			cout << d[i] << "\n";
		}
		else {
			cout << "INF"<<"\n";
		}
	}
}
