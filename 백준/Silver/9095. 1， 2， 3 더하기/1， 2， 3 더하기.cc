#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
	int sum[11];
	sum[0] = 0;
	sum[1] = 1;
	sum[2] = 2;
	sum[3] = 4;
	for (int i = 4; i < 11; ++i)
	{
		sum[i] = sum[i - 1] + sum[i - 2] + sum[i - 3];
	}
	int T;
	cin >> T;
	int n;
	while (T--)
	{
		cin >> n;
		cout << sum[n]<<"\n";
	}
}