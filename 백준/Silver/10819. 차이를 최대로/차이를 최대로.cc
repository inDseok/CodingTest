#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<int> v;
int desc(int a, int b)
{
	return a > b;
}
int main()
{
	int result = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	while(next_permutation(v.begin(), v.end()))
	{
		int sum = 0;
		for (int i = 0; i < v.size() - 1; i++) {
			sum += abs(v[i] - v[i + 1]);
		}
		result = max(result, sum);
	}
	cout << result;
}