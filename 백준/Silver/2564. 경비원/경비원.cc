#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int cal(int dir, int pos, int w, int h) {
	int br = 2 * (w + h);
	int rp = 0;
	switch (dir) {
	case 1:
		rp = pos;
		break;
	case 2:
		rp = br - h - pos;
		break;
	case 3:
		rp = br - pos;
		break;
	case 4:
		rp = w + pos;
		break;
	default:
		break;
	}
	return rp;
}
int main()
{
	int w, h;
	cin >> w >> h;
	int store;
	cin >> store;
	//1 북쪽, 2 남쪽, 3 서쪽, 4 동쪽
	vector<pair<int, int>> q;
	for (int i = 0; i < store; i++) {
		int a, b;
		cin >> a >> b;
		q.push_back(make_pair(a, b));
	}
	int dong_dir=0, dong_pos=0;
	cin >> dong_dir >> dong_pos;
	int dong_start = cal(dong_dir, dong_pos, w, h);
	int sum = 0;
	int rount = 2 * (w + h);
	for (const auto& coord : q) {
		int storePos = cal(coord.first, coord.second, w, h);
		int dist = abs(dong_start - storePos);
		dist = min(dist, rount - dist);
		sum += dist;
	}
	cout << sum;
}