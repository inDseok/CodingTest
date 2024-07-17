#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int solution(vector<vector<int>> maps) {
    n = maps.size();
    m = maps[0].size();
    vector<vector<int>> dist(n, vector<int>(m, -1));
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 1;

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int yy = y + dy[i];
            int xx = x + dx[i];

            if (yy >= 0 && yy < n && xx >= 0 && xx < m && maps[yy][xx] == 1 && dist[yy][xx] == -1) {
                dist[yy][xx] = dist[y][x] + 1;
                q.push({yy, xx});
            }
        }
    }

    return dist[n-1][m-1];
}
