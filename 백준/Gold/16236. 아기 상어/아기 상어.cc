#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int arr[21][21];
int visited[21][21];
int starty, startx;
int babysize = 2;
int eat = 0, result=0;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				arr[i][j] = 0;
				starty = i;
				startx = j;
			}
		}
	}
	while (1) {
		queue<pair<int, int>> q;
		q.push({ starty,startx });
		memset(visited, -1, sizeof(visited));
		visited[starty][startx] = 0;
		vector<pair<int, int>> fish;
		if (eat >= babysize) {
			eat -= babysize;
			babysize++;
		}
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int yy = cur.first + dy[i];
				int xx = cur.second + dx[i];
				if (yy < 0 || yy >= n || xx < 0 || xx >= n) 
					continue;
				if (visited[yy][xx] != -1)
					continue;
				if (babysize<arr[yy][xx])
					continue;
				else if (arr[yy][xx] == babysize || arr[yy][xx] == 0) {
					visited[yy][xx] = visited[cur.first][cur.second] + 1;
					q.push({ yy,xx });
				}
				else if (arr[yy][xx] < babysize || arr[yy][xx] >= 1) {
					visited[yy][xx] = visited[cur.first][cur.second] + 1;
					fish.push_back({ yy,xx });
					q.push({ yy,xx });
				}
			}
		}
		if (fish.size() == 0) {
			cout << result << "\n";
			return 0;
		}
		else if (fish.size() == 1) {
			starty = fish[0].first;
			startx = fish[0].second;
			arr[starty][startx] = 0;
			eat++;
			result += visited[starty][startx];
		}
		else {
			int mindist = 1e9;
			for (auto x : fish) {
				mindist = min(mindist, visited[x.first][x.second]);
			}

			vector<pair<int, int>> minfish;
			for (auto x : fish) {
				if (visited[x.first][x.second] == mindist) {
					minfish.push_back(x);
				}
			}

			sort(minfish.begin(), minfish.end());  // y 우선, x 차순 정렬됨
			starty = minfish[0].first;
			startx = minfish[0].second;
			arr[starty][startx] = 0;
			result += visited[starty][startx];
			eat++;
		}
	}
}