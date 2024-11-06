#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int desc(int a, int b) {
	return a > b;
}
int main()
{
	int n;
	cin >> n;
	vector<string> v;
	vector<int> valpha(26,0);
	for (int i = 0; i < n; i++) {
		string num;
		cin >> num;
		v.push_back(num);
	}
	int result = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			valpha[v[i][j] - 'A'] += pow(10, v[i].size() - 1 - j);
		}
	}
	sort(valpha.begin(), valpha.end(),desc);
	for (int i = 0; i < 10; i++) {
		result += valpha[i] * (9 - i);
	}
	cout << result;
}