#include<iostream>

using namespace std;
int n, s;
int arr[21];
int cnt = 0;
void dfs(int i, int sum)
{
	if (i == n)
		return;
	if (sum + arr[i] == s)
		cnt++;
	dfs(i + 1, sum);
	dfs(i + 1, sum + arr[i]);
}
int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dfs(0, 0);
	cout << cnt;
}