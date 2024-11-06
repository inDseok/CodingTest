#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int cows[50001];
vector<pair<int, int>> v[50001];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	for (int i = 0; i <= n; i++) {
		cows[i] = INT32_MAX;
	}
	cows[1] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,1 });
	while (!pq.empty()) {
		int curcost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int nextcost = curcost + v[cur][i].second;
			int next = v[cur][i].first;
			if (cows[next] > nextcost) {
				cows[next] = nextcost;
				pq.push({ -nextcost,next });
			}
		}
	}
	cout << cows[n]<<"\n";
}