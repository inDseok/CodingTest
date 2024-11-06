#include<iostream>
#include<string>
using namespace std;
int t, n;
void dfs(int a, string s, int sum, int now, char state) 
{
	if (a <= n) {
		if (state == '+') {
			dfs(a + 1, s + ' ' + to_string(a), sum, now * 10 + a, '+');
			dfs(a + 1, s + '+' + to_string(a), sum + now, a , '+');
			dfs(a + 1, s + '-' + to_string(a), sum + now, a, '-');
		}
		else if (state == '-') {
			dfs(a + 1, s + ' ' + to_string(a), sum, now * 10 + a, '-');
			dfs(a + 1, s + '+' + to_string(a), sum - now, a, '+');
			dfs(a + 1, s + '-' + to_string(a), sum - now, a, '-');
		}
	}
	else {
		if (state == '+') {
			sum += now;
		}
		else if (state == '-') {
			sum -= now;
		}
		if (sum == 0) {
			cout << s << "\n";
		}
	}
}
int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		dfs(2,"1",0,1,'+');
		cout << "\n";
	}
}