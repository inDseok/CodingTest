#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int M, N;
	cin >> M >> N;
	int num = 1;
	for (int i = M; i <= N; i++) {
		if (i == 1) {
			continue;
		}
		for (int j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) {
				num = -1;
				break;
			}
		}
		if (num == 1) {
			cout << i << "\n";
		}
		num = 1;
	}
}