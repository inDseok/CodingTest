#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int cnt=0;
vector<int> v(200001, 0);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	queue<int> q;
	int n, k;
	cin >> n >> k;
	q.push(n);
	v[n] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == k) {
			cout << v[k] - 1;
			return 0;
		}
		if (cur - 1 >= 0 && !v[cur - 1]) {
			v[cur - 1] = v[cur] + 1;
			q.push(cur - 1);
		}
		if (cur + 1 < 200001 && !v[cur + 1]) {
			v[cur + 1] = v[cur] + 1;
			q.push(cur + 1);
		}
		if (cur * 2 < 200001 && !v[cur * 2]) {
			v[cur * 2] = v[cur] + 1;
			q.push(cur * 2);
		}
	}
}
