#include<iostream>

using namespace std;

int main()
{
	long long a, b, c;
	cin >> a >> b >> c;
	long long result = 1,temp, tempb;
	while (b) {
		if (b == 1) {
			result = result * a % c;
			break;
		}
		temp = a;
		for (tempb = 2; tempb <= b; tempb *= 2)
			temp = temp * temp % c;
		result = result * temp % c;
		tempb /= 2;
		b -= tempb;
	}
	cout << result;
}