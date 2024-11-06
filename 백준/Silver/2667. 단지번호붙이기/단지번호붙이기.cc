#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 26


bool map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int num = 0;
vector<int> house;
void dfs(int y, int x) {
	int newx;
	int newy;
	for (int i = 0; i < 4; i++) {
		newx = x + dx[i];
		newy = y + dy[i];
		if (!visited[newy][newx] && map[newy][newx]) {
			visited[newy][newx] = 1;
			num++;
			dfs(newy, newx);
		}
	}
}
int main() {
	int size;
	cin >> size;
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			if (map[i][j] && !visited[i][j]) {
				visited[i][j] = true;
				num++;
				dfs(i, j);
				house.push_back(num);
				num = 0;
			}
		}
	}
	cout << house.size() << endl;
	sort(house.begin(), house.end());
	for (int i = 0; i < house.size(); i++) {
		cout << house[i] << endl;
	}
}