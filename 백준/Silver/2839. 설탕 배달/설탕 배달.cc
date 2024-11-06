#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

int sugar(int N)
{
	int max = N / 5;
	for (int i = max; i > 0; i--) {
		int mod;
		int num;
		mod = N - i * 5;
		if (mod % 3 == 0) {
			num = mod / 3 + i;
			return num;
		}
	}
	int min=N/3;
	for (int j = min; j > 0; j--) {
		int mod2;
		int num2;
		mod2 = N - j * 3;
		if (mod2 % 5 == 0) {
			num2 = mod2 / 5 + j;
			return num2;
		}
	}
	return 0;
}
int main()
{
	int N;
	cin >> N;
	if (sugar(N) == 0)
		cout << -1;
	else
		cout << sugar(N);
	return 0;
}
