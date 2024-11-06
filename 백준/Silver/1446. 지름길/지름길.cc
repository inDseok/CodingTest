#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, d;
int s, e, w;
vector<pair<int, int>> v[10001];
vector<int> dist(10001, 9999999);
int main() {
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> s >> e >> w;
		v[e].push_back({ s,w });
	}
	dist[0] = 0;
	for (int i = 1; i <= d; i++) {
		if (v[i].size() == 0) {
			dist[i] = dist[i - 1] + 1;
		}
		else {
			for (auto j : v[i]) {
				dist[i] = min(dist[i], min(dist[i - 1] + 1, dist[j.first] + j.second));
			}
		}
	}
	cout << dist[d];
}