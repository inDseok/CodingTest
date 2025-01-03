#include<iostream>
#include <vector>
using namespace std;

int arr[10001];
int main() {
	int n;
	long long k;
	cin >> n >> k;
	long long sum = 0;
	long long max = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (max < arr[i])
			max = arr[i];
	}
	long long min = 1;
	long long line = 0;
	while (min<=max) {
		long long mid = (min + max) / 2;
		sum = 0;
		for (int i = 0; i < n; i++) {
			sum += arr[i] / mid;
		}
		if (sum >= k) {
			line = mid;
			min = mid + 1;
		}
		else
			max=mid-1;
	}
	cout << line;
	return 0;
}