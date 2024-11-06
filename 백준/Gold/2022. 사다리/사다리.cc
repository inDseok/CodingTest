#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
	double x, y, c;
	cin >> x >> y >> c;
	double l = 0;
	double r = min(x, y);
	for (int i = 0; i < 1000; i++) {
		double k = (r + l) / 2.0;
		double X = sqrt(x * x - k * k);
		double Y = sqrt(y * y - k * k);
		double c0 = k * c / Y;
		if (-(X * c0 / k) + X > c) {
			l = k;
		}
		else
			r = k;
	}
	printf("%.3lf",l);
}