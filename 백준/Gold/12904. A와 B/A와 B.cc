#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
string s1, s2;
int main()
{
	cin >> s1 >> s2;
	for (int i = s2.size()-1; i >= s1.size(); i--) {
		if (s2[i] == 'A') {
			s2.pop_back();
		}
		else if (s2[i] == 'B') {
			s2.pop_back();
			reverse(s2.begin(), s2.end());
		}
	}
	if (s1 == s2) {
		cout << '1';
	}
	else {
		cout << '0';
	}
	/*while (1)
	{
		if (s2[s2.size() - 1] == 'A') {
			s2.pop_back();
		}
		else {
			s2.pop_back();
			reverse(s2.begin(), s2.end());
		}
		if (s1.size() == s2.size()) {
			if (s1 == s2) {
				cout << '1';
			}
			else {
				cout << '0';
			}
			break;
		}
	}*/
}