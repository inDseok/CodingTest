#include<iostream>
using namespace std;

int fib(int num)
{
	long long zero=0, one=1, c;
	if (num == 0)
		cout << "1 0\n";
	else if (num == 1)
		cout << "0 1\n";
	else {
		for (int i = 1; i < num; i++) {
			c = zero + one;
			zero = one;
			one = c;
		}
		cout << zero << " " << one<<'\n';
	}
	return 0;
}

int main() {
	int T;
	cin >> T;
	while (T--)
	{
		int num;
		cin >> num;
		fib(num);
	}
}