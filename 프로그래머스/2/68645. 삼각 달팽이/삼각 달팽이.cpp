#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dir[2][3] = {{1, 0, -1}, {0, 1, -1}};

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> temp(n, vector<int>(n, 0));
    int sum = n * (n + 1) / 2;
    int d = 0;
    int dy = 0, dx = 0;

    for (int i = 1; i <= sum; i++) {
        temp[dy][dx] = i;
        
        int ny = dy + dir[0][d];
        int nx = dx + dir[1][d];

        if (ny >= n || nx >= n || ny < 0 || nx < 0 || temp[ny][nx] != 0) {
            d = (d + 1) % 3;
            ny = dy + dir[0][d];
            nx = dx + dir[1][d];
        }

        dy = ny;
        dx = nx;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            answer.push_back(temp[i][j]);
        }
    }

    return answer;
}
