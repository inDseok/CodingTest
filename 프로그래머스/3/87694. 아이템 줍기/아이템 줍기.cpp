#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring> // memset을 사용하기 위해 추가
using namespace std;

int board[101][101];
int dist[101][101];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;

    // dist 배열을 -1로 초기화
    memset(dist, -1, sizeof(dist));

    // board 초기화 및 직사각형 그리기
    for (int i = 0; i < rectangle.size(); i++) {
        for (int j = rectangle[i][1] * 2; j <= rectangle[i][3] * 2; j++) {
            for (int k = rectangle[i][0] * 2; k <= rectangle[i][2] * 2; k++) {
                if ((j == rectangle[i][1] * 2 || j == rectangle[i][3] * 2 || k == rectangle[i][0] * 2 || k == rectangle[i][2] * 2) && board[j][k] != -1) {
                    board[j][k] = 1; // 경계선 그리기
                } else {
                    board[j][k] = -1; // 내부 채우기
                }
            }
        }
    }

    // BFS를 사용하여 최단 경로 찾기
    queue<pair<int, int>> q;
    q.push({characterX * 2, characterY * 2});
    dist[characterY * 2][characterX * 2] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            // 범위와 조건 확인
            if (xx < 0 || xx >= 101 || yy < 0 || yy >= 101) continue;
            if (dist[yy][xx] != -1 || board[yy][xx] != 1) continue;

            q.push({xx, yy});
            dist[yy][xx] = dist[y][x] + 1;
        }
    }

    // 아이템 위치까지의 거리 계산
    answer = dist[itemY * 2][itemX * 2] / 2;
    return answer;
}
