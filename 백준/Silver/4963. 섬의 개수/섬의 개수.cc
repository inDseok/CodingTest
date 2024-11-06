#include<iostream>
#include<cstring>
using namespace std;
//우,하,좌,상,우상,우하,좌상,좌하
int dx[8] = { 1,0,-1,0,1,1,-1 ,-1 };
int dy[8] = { 0,1,0,-1,-1,1,-1,1 };
int arr[51][51];
int visited[51][51];
int w, h;
void dfs(int y,int x)
{
	visited[y][x] = 1;
	for (int i = 0; i < 8; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= 0 && yy >= 0 && xx < w && yy < h) {
			if (arr[yy][xx] == 1 && !visited[yy][xx]) {
				visited[yy][xx] = 1;
				dfs(yy, xx);
			}
		}
	}
}
int main()
{
	while (1)
	{
		int cnt = 0;
		cin >> w >> h;
		if (w == 0 && h == 0) {
			return 0;
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (arr[i][j] == 1 && !visited[i][j]) {
					cnt++;
					dfs(i, j);
				}
			}
		}
		cout << cnt<<"\n";
		memset(arr, false, sizeof(arr));
		memset(visited, false, sizeof(visited));
	}
	return 0;
}