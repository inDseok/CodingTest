#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, x;
vector<pair<int, int>> v[1001], reverse_v[1001];
#define INF 99999999

vector<int> dijkstra(vector<pair<int, int>> graph[]) {
    vector<int> dist(n + 1, INF);
    dist[x] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, x });

    while (!pq.empty()) {
        int d = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (d > dist[cur]) continue;

        for (auto& edge : graph[cur]) {
            int next_d = d + edge.first;
            int next_cur = edge.second;

            if (dist[next_cur] > next_d) {
                dist[next_cur] = next_d;
                pq.push({ next_d, next_cur });
            }
        }
    }

    return dist;
}

int main() {
    cin >> n >> m >> x;

    for (int i = 0; i < m; i++) {
        int start, end, pay;
        cin >> start >> end >> pay;
        v[start].push_back({ pay, end });         // 순방향
        reverse_v[end].push_back({ pay, start }); // 역방향
    }

    vector<int> dist_to_x = dijkstra(v);         // 각 노드에서 X로 가는 거리
    vector<int> dist_from_x = dijkstra(reverse_v); // X에서 각 노드로 가는 거리

    int max_dist = 0;
    for (int i = 1; i <= n; i++) {
        max_dist = max(max_dist, dist_to_x[i] + dist_from_x[i]);
    }

    cout << max_dist;
    return 0;
}
