#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
bool compare(pair<int, string> v1, pair<int, string> v2) {
	return v1.first < v2.first;
}
int main() {
	int n;
	vector<pair<int, string>> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int age;
		string name;
		cin >> age >> name;
		v.push_back({ age,name });
	}
	stable_sort(v.begin(), v.end(),compare);

	for (int i = 0; i < n; i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
	return 0;
}