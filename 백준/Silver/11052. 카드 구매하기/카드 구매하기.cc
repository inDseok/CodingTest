#include<iostream>
#include<algorithm>
using namespace std;
int n;
int arr[1001];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; i - j >= j; j++) {
			arr[i] = max(arr[i], arr[i-j] + arr[j]);
		}
	}
	cout << arr[n];
}