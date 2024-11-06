#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, k, l;
int arr[101][101]={0,};
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
	cin >> n;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int row, col;
		cin >> row >> col;
		arr[row][col] = 1;
	}
	cin >> l;
	vector<pair<int, char>> command;
	for (int i = 0; i < l; i++) {
		int second;
		char dir;
		cin >> second >> dir;
		command.push_back({second,dir});
	}
	int xx= 1, yy = 1;
	vector<pair<int, int>> body;
	body.push_back({ yy,xx });
	int cur_dir = 0;
	int time = 0;
	int idx = 0;
	while (1) {
		time++;
		int cur_yy = yy + dy[cur_dir];
		int cur_xx = xx + dx[cur_dir];

		if (cur_yy < 1 || cur_yy > n || cur_xx < 1 || cur_xx > n) {
			cout << time;
			return 0;
		}
		for (int i = 0; i < body.size(); i++) {
			if (cur_yy == body[i].first && cur_xx == body[i].second) {
				cout << time;
				return 0;
			}
		}
		body.push_back({ cur_yy, cur_xx });
		if (arr[cur_yy][cur_xx] == 1) {
			arr[cur_yy][cur_xx] = 0;
		}
		else {
			body.erase(body.begin());
		}
		yy = cur_yy;
		xx = cur_xx;
		if (idx < l && time == command[idx].first) {
			if (command[idx].second == 'D') {
				cur_dir = (cur_dir + 1) % 4;
			}
			else if (command[idx].second == 'L') {
				cur_dir = (cur_dir + 3) % 4; 
			}
			idx++;
		}
	}
	cout << time;
	return 0;
}