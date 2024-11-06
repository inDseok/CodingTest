#include<iostream>
#include<vector>
using namespace std;
int gcd(int m, int n)
{
	if (n == 0)
		return m;
	else {
		return gcd(n, m % n);
	}
}
int main()
{
	int n, s;
	cin >> n >> s;

	vector<int> v;
	for (int i = 0; i < n; i++) {
		int r;
		cin >> r;
		v.push_back(abs(s-r));
	}
	int result = v[0];
	for (int i = 1; i < n; i++) {
		result = gcd(result, v[i]);
	}
	cout << result;
	return 0;
}