#include<iostream>
using namespace std;

int main() {
	int people[15][15]={0,};
	for (int i = 0; i < 15; i++) {
		people[0][i] = i;
	}
	for (int i = 1; i < 15; i++) {
		people[i][0] = 0;
	}
	for (int i = 1; i < 15; i++) {
		people[i][1] = 1;
	}
	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			people[i][j] = people[i][j-1] + people[i-1][j];
		}
	}
	int T;
	cin >> T;
	int floor, ho;
	while (T--) {
		cin >> floor >> ho;
		cout << people[floor][ho] << "\n";
	}
}