#include<iostream>

using namespace std;

int main() {
	int count = 0;
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int h, t, o;
		if (i >= 100) {
			o = i % 10;
			t = (i / 10) % 10;
			h = i / 100;
			if ((h - t) == (t - o))
				count++;
		}
		else {
			count++;
		}
	}
	cout << count;
}