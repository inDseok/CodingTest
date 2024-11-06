#include<iostream>
#include<string.h>
using namespace std;
int arr[101];
int result[101];
int visited[101];
int n,cnt=1;
int dfs(int start, int current) {
	if (!visited[current]) {
		visited[current] = 1;
		return dfs(start, arr[current]);
	}
	else {
		if (start == current)
			return 1;
		else
			return 0;
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		if (dfs(i, i)) {
			result[i] = cnt++;
		}
		memset(visited, 0, 101 * sizeof(int));
	}
	cout << cnt - 1 << "\n";
	for (int i = 1; i <= n; i++) {
		if (result[i])
			cout << i << "\n";
	}
}