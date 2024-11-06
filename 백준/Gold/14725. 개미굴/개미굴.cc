#include<iostream>
#include<set>
#include<cstring>
#include<algorithm>
using namespace std;
int n, k;
string t;
set<string> s;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		string tmp = "";
		string str = "";
		for (int j = 0; j < k; j++) {
			cin >> tmp;
			str += "-" + tmp;
			s.insert(str);
		}
	}
	for (auto value : s) {
		int cnt = count(value.begin(), value.end(), '-');
		int pos = value.find_last_of("-");
		string tmp = value.substr(pos + 1);
		for (int i = 0; i < cnt - 1; i++)
			cout << "--";
		cout << tmp << "\n";
	}
}