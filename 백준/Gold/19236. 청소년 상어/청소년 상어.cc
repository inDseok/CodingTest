#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Fish {
    int y, x, dir, alive;
};

int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,-1,-1,-1,0,1,1,1 };

int ans = 0;

void moveFish(vector<Fish>& fish, int board[4][4], int sy, int sx) {
    for (int i = 1; i <= 16; i++) {
        if (fish[i].alive == 0) continue;
        int y = fish[i].y;
        int x = fish[i].x;
        int dir = fish[i].dir;
        for (int d = 0; d < 8; d++) {
            int ndir = (dir + d) % 8;
            int ny = y + dy[ndir];
            int nx = x + dx[ndir];
            if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) continue;
            if (ny == sy && nx == sx) continue;
            int target = board[ny][nx];
            if (target != 0) {
                swap(fish[i].y, fish[target].y);
                swap(fish[i].x, fish[target].x);
                board[y][x] = target;
                board[ny][nx] = i;
            }
            else {
                fish[i].y = ny;
                fish[i].x = nx;
                board[y][x] = 0;
                board[ny][nx] = i;
            }
            fish[i].dir = ndir;
            break;
        }
    }
}

void dfs(vector<Fish> fish, int board[4][4], int sy, int sx, int score) {
    ans = max(ans, score);
    
    moveFish(fish, board, sy, sx);

    int dir = fish[board[sy][sx]].dir;

    for (int step = 1; step <= 3; step++) {
        int ny = sy + dy[dir] * step;
        int nx = sx + dx[dir] * step;

        if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) continue;
        if (board[ny][nx] == 0) continue;

        vector<Fish> tmpFish = fish;
        int tmpBoard[4][4];
        memcpy(tmpBoard, board, sizeof(tmpBoard));

        int eatenFish = board[ny][nx];
        tmpFish[eatenFish].alive = 0;
        tmpBoard[sy][sx] = 0;
        tmpBoard[ny][nx] = eatenFish;

        dfs(tmpFish, tmpBoard, ny, nx, score + eatenFish);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int board[4][4];
    vector<Fish> fish(17); // 1~16번 물고기

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int a, b;
            cin >> a >> b;
            board[i][j] = a;
            fish[a] = { i, j, b - 1, 1 };
        }
    }

    int sharkY = 0, sharkX = 0;
    int firstFish = board[sharkY][sharkX];
    int score = firstFish;
    fish[firstFish].alive = 0;
    dfs(fish, board, sharkY, sharkX, score);

    cout << ans << "\n";
    return 0;
}
