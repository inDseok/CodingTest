#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
int sy, sx, ey, ex;

struct customer {
	int y, x, idx;
};
int n;
bool visited[11];
vector<customer> v(10);
int result, current;
void dfs(int y, int x, int cnt) {
	if (cnt == n) {
		current += abs(ey - y) + abs(ex - x);
		if (result > current) {
			result = current;
		}
		current-= abs(ey - y) + abs(ex - x);
	}
	else {
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				visited[i] = true;
				current += abs(v[i].y - y) + abs(v[i].x - x);

				dfs(v[i].y, v[i].x, cnt + 1);
				current -= abs(v[i].y - y) + abs(v[i].x - x);
				visited[i] = false;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		cin >> n;
		cin >> sy >> sx;
		cin >> ey >> ex;
		result = 1e9;
		current = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i].y >> v[i].x;
			v[i].idx = i;
		}
		memset(visited, false,sizeof(visited));
		dfs(sy, sx, 0);
		cout << "#" << tt << " " << result << "\n";
	}
}