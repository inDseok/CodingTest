#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int arr[101][101];
int r, c, m;
struct shark {
	int rpos, cpos, speed, dir, z;//위치 속력 이동방향 크기
};
vector<shark> s;
int result = 0;
//위1 아래2 3오른쪽 4왼쪽
bool asce(shark s1, shark s2) {
	return s1.rpos < s2.rpos;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c >> m;
	s = vector<shark>(m);
	for (int i = 0; i < m; i++) {
		cin >> s[i].rpos >> s[i].cpos >> s[i].speed >> s[i].dir >> s[i].z;
	}
	
	for (int t = 1; t <= c; t++) {
		vector<shark> get_shark;
		for (int i = 0; i < s.size(); i++) {
			if (t == s[i].cpos) {
				get_shark.push_back(s[i]);
			}
		}
		if (get_shark.size() > 1) {
			sort(get_shark.begin(), get_shark.end(),asce);
		}
		if (!get_shark.empty()) {
			shark catch_shark = get_shark[0];
			result += catch_shark.z;
			for (auto it = s.begin(); it != s.end(); it++) {
				if (it->rpos == catch_shark.rpos && it->cpos == catch_shark.cpos) {
					s.erase(it);
					break;
				}
			}
		}
		for (int i = 0; i < s.size(); i++) {
			// 방향에 따라 속도 최적화
			if (s[i].dir == 1 || s[i].dir == 2) {
				int move_len = (r - 1) * 2;
				s[i].speed %= move_len;
			}
			else {
				int move_len = (c - 1) * 2;
				s[i].speed %= move_len;
			}

			// 실제 이동 처리
			int move = s[i].speed;
			while (move--) {
				if (s[i].dir == 1) { // 위
					if (s[i].rpos == 1) s[i].dir = 2; // 방향 반전
					s[i].rpos += (s[i].dir == 1 ? -1 : 1);
				}
				else if (s[i].dir == 2) { // 아래
					if (s[i].rpos == r) s[i].dir = 1;
					s[i].rpos += (s[i].dir == 1 ? -1 : 1);
				}
				else if (s[i].dir == 3) { // 오른쪽
					if (s[i].cpos == c) s[i].dir = 4;
					s[i].cpos += (s[i].dir == 3 ? 1 : -1);
				}
				else if (s[i].dir == 4) { // 왼쪽
					if (s[i].cpos == 1) s[i].dir = 3;
					s[i].cpos += (s[i].dir == 3 ? 1 : -1);
				}
			}
		}

		map<pair<int, int>, shark> temp;

		for (int i = 0; i < s.size(); i++) {
			int nr = s[i].rpos;
			int nc = s[i].cpos;

			pair<int, int> pos = { nr,nc };
			if (temp.find(pos) == temp.end()) {
				temp[pos] = s[i];
			}
			else {
				if (temp[pos].z < s[i].z) {
					temp[pos] = s[i];
				}
			}
		}
		s.clear();
		for (auto it : temp) {
			s.push_back(it.second);
		}
	}
	cout << result;
}