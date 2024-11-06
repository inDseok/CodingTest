#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int num[10];
	int max,c;
	for (int i = 1; i <= 9; ++i)
		cin >> num[i];
	max = 0;
	for (int i = 1; i <= 9; ++i) {
		if (max < num[i]) {
			max = num[i];
			c = i;
		}
	}
	cout << max<<"\n"<< c;
}