#include<iostream>
using namespace std;

int main() {
	int size;
	cin >> size;
	int sol[1001];
	sol[0] = 0;
	sol[1] = 1;
	sol[2] = 2;
	for (int i = 3; i <= size; i++) {
		sol[i] = (sol[i - 1] + sol[i - 2]) % 10007;
	}
	cout << sol[size];
}