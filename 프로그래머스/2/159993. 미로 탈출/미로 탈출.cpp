#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int arr[101][101];
int visited[101][101];
pair<int,int> lever;
pair<int,int> start;
pair<int,int> Exit;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int row, col;

bool is_range(int y, int x) {
    return y >= 0 && y < row && x >= 0 && x < col;
}

int bfs(int y, int x, int ey, int ex) {
    memset(visited, 0, sizeof(visited)); // 매 BFS 호출마다 visited 배열 초기화
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = 1; // 시작 지점도 방문한 것으로 표시 (거리 1로 시작)

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (cur.first == ey && cur.second == ex)
            return visited[cur.first][cur.second] - 1; // 거리에서 1을 빼서 실제 이동 횟수 반환

        for (int d = 0; d < 4; d++) {
            int yy = cur.first + dy[d];
            int xx = cur.second + dx[d];
            if (!is_range(yy, xx))
                continue;
            if (!visited[yy][xx] && arr[yy][xx] != -1) {
                visited[yy][xx] = visited[cur.first][cur.second] + 1;
                q.push({yy, xx});
            }
        }
    }
    return -1; // 도달할 수 없는 경우 -1 반환
}

int solution(vector<string> maps) {
    int answer = 0;
    row = maps.size();
    col = maps[0].size();

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (maps[i][j] == 'X')
                arr[i][j] = -1;
            else
                arr[i][j] = 0;

            if (maps[i][j] == 'S')
                start = {i, j};
            else if (maps[i][j] == 'E')
                Exit = {i, j};
            else if (maps[i][j] == 'L')
                lever = {i, j};
        }
    }

    int stol = bfs(start.first, start.second, lever.first, lever.second);
    if (stol == -1)
        return -1;

    int ltoe = bfs(lever.first, lever.second, Exit.first, Exit.second);
    if (ltoe == -1)
        return -1;

    answer = stol+ltoe;
    return answer;
}
