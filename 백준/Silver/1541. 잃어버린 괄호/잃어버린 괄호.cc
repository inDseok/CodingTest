#include<iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	string num;
	int ans=0;
	int minans = 0;
	bool minus = false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '-' || s[i] == '+') {
			if (minus==true) {
				ans -= stoi(num);
				num = "";
			}
			else {
				ans += stoi(num);
				num = "";
			}
		}
		else {
			num += s[i];
		}
		if (s[i] == '-')
			minus = true;
	}
	if (minus == true) {
		ans = ans - stoi(num);
	}
	else
		ans = ans + stoi(num);
	cout << ans;
}