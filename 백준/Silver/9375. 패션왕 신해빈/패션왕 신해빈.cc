#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		map<string, int> m;
		for (int i = 0; i < n; i++)
		{
			string name, kind;
			cin >> name >> kind;

			if (m.find(kind) == m.end()) { //kind가 존재하지 않으면 end()반환
				m.insert(make_pair(kind, 2));
			}
			else //kind가 존재하면
				m[kind]++;
		}
		int result = 1;
		for (auto iter = m.begin(); iter != m.end(); iter++) {
			result = result * iter->second;
		}
		result--;
		cout << result << "\n";
	}
}