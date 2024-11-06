#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string s;
bool chk[101] = { false };
int main()
{
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		string res = "z";
		int idx = 0;
		for (int j = 0; j < s.size(); j++) {
			if (chk[j])
				continue;
			string t = "";
			chk[j] = true;
			for (int k = 0; k < s.size(); k++) {
				if (chk[k])
					t.push_back(s[k]);
			}
			chk[j] = false;
			if (res > t) {
				res = t;
				idx = j;
			}
		}
		chk[idx] = true;
		cout << res << "\n";
	}
}