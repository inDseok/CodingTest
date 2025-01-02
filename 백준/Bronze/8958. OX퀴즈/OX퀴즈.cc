#include<iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		int score = 0;
		bool circle = false;
		int num = 1;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'O') {
				if (circle == true) {
					num++;
					score += num;
				}
				else {
					score += num;
				}
				circle = true;
			}
			else {
				circle = false;
				num = 1;
			}
		}
		cout << score << "\n";
	}
	return 0;
}