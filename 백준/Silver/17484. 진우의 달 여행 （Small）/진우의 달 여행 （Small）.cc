#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int arr[100][7]; // 연료 소모 배열
int dp[100][7][3]; // dp 배열: [행][열][이전 방향(0: 왼쪽 대각선, 1: 위, 2: 오른쪽 대각선)]

int main() {
    cin >> n >> m;

    // 연료 소모 배열 입력 받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    // 첫 번째 행의 dp 초기화 (첫 번째 행에서는 이전 방향이 없으므로 arr 값 그대로 복사)
    for (int j = 0; j < m; j++) {
        for (int k = 0; k < 3; k++) {
            dp[0][j][k] = arr[0][j];
        }
    }

    // dp 테이블 채우기
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 왼쪽 대각선에서 오는 경우 (이전 방향이 0이 아닌 경우만 고려)
            if (j > 0) {
                dp[i][j][0] = min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]) + arr[i][j];
            }
            else {
                dp[i][j][0] = 1e9; // 경계 바깥은 무한대 처리
            }

            // 바로 위에서 오는 경우 (이전 방향이 1이 아닌 경우만 고려)
            dp[i][j][1] = min(dp[i - 1][j][0], dp[i - 1][j][2]) + arr[i][j];

            // 오른쪽 대각선에서 오는 경우 (이전 방향이 2가 아닌 경우만 고려)
            if (j < m - 1) {
                dp[i][j][2] = min(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]) + arr[i][j];
            }
            else {
                dp[i][j][2] = 1e9; // 경계 바깥은 무한대 처리
            }
        }
    }

    // 마지막 행에서 최소값 찾기
    int result = 1e9;
    for (int j = 0; j < m; j++) {
        for (int k = 0; k < 3; k++) {
            result = min(result, dp[n - 1][j][k]);
        }
    }

    cout << result;
    return 0;
}
