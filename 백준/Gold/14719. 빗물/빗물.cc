#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int h, w;
	cin >> h >>w;
	int arr[501];
	int sum = 0;
	for (int i = 1; i <= w; i++) {
		cin >> arr[i];
	}
	int left = 0, right = 0;
	int block;
	for (int i = 2; i < w; i++) {
		for (int j = 1; j < i; j++) {
			left = max(left, arr[j]);
		}
		for (int k = i + 1; k <= w; k++) {
			right = max(right, arr[k]);
		}
		block = min(left, right);
		if (block > arr[i]) {
			sum += block - arr[i];
		}
		left = 0;
		right = 0;
	}
	cout << sum;
}