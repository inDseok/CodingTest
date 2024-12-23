#include<iostream>
#include <vector>
using namespace std;

int main() {
	int sum = 0;
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	sum = a * a + b * b + c * c + d * d + e * e;
	sum = sum%10;
	cout << sum;
	return 0;
}