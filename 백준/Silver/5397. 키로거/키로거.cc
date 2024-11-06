#include<iostream>
#include<string>
#include<list>
using namespace std;
int main()
{
	int T;
	cin >> T;

	while (T--) {
		string L;
		cin >> L;
		list<char> password;
		list<char>::iterator pw_iter = password.begin();
		for (int i = 0; i < L.size(); i++)
		{
			switch (L[i]) {
			case '<':
				if (pw_iter != password.begin()) {
					pw_iter--;
				}
				break;
			case '>':
				if (pw_iter != password.end()) {
					pw_iter++;
				}
				break;
			case '-':
				if (pw_iter != password.begin()) {
					pw_iter = password.erase(--pw_iter);
				}
				break;
			default:
				password.insert(pw_iter, L[i]);
				break;
			}
		}
		for (pw_iter = password.begin(); pw_iter != password.end(); ++pw_iter) {
			cout << *pw_iter;
		}
		cout << "\n";
	}
	return 0;
}

