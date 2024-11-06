#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
double arr[51];
int result;
double g, m;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		m = 1000000000;
		for (int j = i-1; j >= 1; j--) {
			g = (arr[i] - arr[j]) / (double(i) - double(j));
			if (g < m) {
				cnt++;
				m = g;
			}
		}
		m = -1000000000;
		for (int j = i+1; j <= n; j++) {
			g = (arr[j] - arr[i]) / (double(j) - double(i));
			if (g > m) {
				cnt++;
				m = g;
			}
		}
		result = max(result, cnt);
	}
	cout << result;
}