#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n;
int arr[21][21];
int visited[21][21];
pair<int, int> baby;
int dy[4] = { 0,-1,0,1 };
int dx[4] = {-1,0,1,0};
int x, y, babysize = 2, eat = 0;
int result = 0;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				y = i;
				x = j;
				arr[i][j] = 0;
			}
		}
	}
	while (1) {
		memset(visited, -1, sizeof(visited));
		visited[y][x] = 0;
		queue<pair<int, int>> q;
		vector<pair<int, int>> fish;
		if (eat >= babysize) {
			eat -= babysize;
			babysize++;
		}
		q.push({ y,x });
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = cur.first + dy[i];
				int nx = cur.second + dx[i];
				if (nx<1 || nx>n || ny<1 || ny>n)
					continue;
				if (visited[ny][nx] != -1)
					continue;
				if (arr[ny][nx] > babysize)
					continue;
				else if (arr[ny][nx] == babysize || arr[ny][nx] == 0) {
					visited[ny][nx] = visited[cur.first][cur.second] + 1;
					q.push({ ny,nx });
				}
				else if (arr[ny][nx] < babysize || arr[ny][nx] >= 1) {
					visited[ny][nx] = visited[cur.first][cur.second] + 1;
					fish.push_back({ ny,nx });
					q.push({ ny,nx });
				}
			}
		}
		if (fish.size() == 0) {
			cout << result << "\n";
			return 0;
		}
		else if (fish.size() == 1) {
			y = fish[0].first;
			x = fish[0].second;
			arr[y][x] = 0;
			eat++;
			result += visited[y][x];
		}
		else {
			int mindist = 99999999;
			for (auto& x : fish) {
				mindist = min(mindist, visited[x.first][x.second]);
			}
			int mincnt = 0;
			vector<pair<int, int>> minfish;
			for (auto& x : fish) {
				if (mindist == visited[x.first][x.second]) {
					minfish.push_back({ x.first,x.second });
				}
			}
			if (minfish.size() == 1) {
				y = minfish[0].first;
				x = minfish[0].second;
				arr[y][x] = 0;
				result += visited[y][x];
				eat++;
			}
			else {
				sort(minfish.begin(), minfish.end());
				y = minfish[0].first;
				x = minfish[0].second;
				arr[y][x] = 0;
				result += visited[y][x];
				eat++;
			}
		}
	}
}