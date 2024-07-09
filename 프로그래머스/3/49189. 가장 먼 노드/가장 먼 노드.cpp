#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
int max_dist=0;
int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> graph(n + 1);
    vector<int> dist(n + 1, -1);
    vector<bool> visited(n + 1, false);
    queue<int> q;

    for (auto& e : edge) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }

    q.push(1);
    dist[1] = 0;
    visited[1] = true;

    int max_dist = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
            if (!visited[next]) {
                visited[next] = true;
                dist[next] = dist[cur] + 1;
                q.push(next);
                max_dist = max(max_dist, dist[next]);
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == max_dist) {
            answer++;
        }
    }

    return answer;
}