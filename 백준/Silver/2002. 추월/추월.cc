#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	map<string, int> s_m;
	string v[1001];
	for (int i = 1; i <=n ; i++) {
		string car_num;
		cin >> car_num;
		s_m[car_num] = i;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		string car_num;
		cin >> car_num;
		v[i] = car_num;
	}
	for (int i = 1; i < n; i++) {
		for (int j = i; j <= n; j++) {
			if (s_m[v[i]] > s_m[v[j]]) {
				cnt++;
				break;
			}
		}
	}
	cout << cnt;
}
