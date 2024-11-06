#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int n, m, result, temp;
int arr[9][9], visited[9][9];
vector<pair<int, int>> virus, wall;

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int yy = y + dy[i];
        int xx = x + dx[i];
        if (yy < 1 || xx < 1 || yy > n || xx > m)
            continue;
        if (visited[yy][xx] == 1 || arr[yy][xx] == 1)
            continue;
        dfs(yy, xx);
    }
    return;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0)
                wall.push_back({ i, j });
            if (arr[i][j] == 2)
                virus.push_back({ i, j });
        }
    }

    int wallSize = wall.size();
    for (int i = 0; i < wallSize; i++) {
        for (int j = i + 1; j < wallSize; j++) {
            for (int k = j + 1; k < wallSize; k++) {
                memset(visited, 0, sizeof(visited));
                temp = 0;

                arr[wall[i].first][wall[i].second] = 1;
                arr[wall[j].first][wall[j].second] = 1;
                arr[wall[k].first][wall[k].second] = 1;

                for (pair<int, int> v : virus)
                    dfs(v.first, v.second);

                for (int ii = 1; ii <= n; ii++) {
                    for (int jj = 1; jj <= m; jj++) {
                        if (arr[ii][jj] == 0 && visited[ii][jj] == 0)
                            temp++;
                    }
                }

                result = max(result, temp);

                arr[wall[i].first][wall[i].second] = 0;
                arr[wall[j].first][wall[j].second] = 0;
                arr[wall[k].first][wall[k].second] = 0;
            }
        }
    }

    cout << result;
}
