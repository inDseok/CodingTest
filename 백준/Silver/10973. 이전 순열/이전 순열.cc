#include<iostream>
#include <algorithm>
using namespace std;
int n;
int arr[10001];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin>>arr[i];
	}
	int temp = 0;
	for (int i = n - 1; i > 0; i--) {
		if (arr[i] < arr[i - 1]) {
			temp = i;
			break;
		}
	}
	if (temp == 0) {
		cout << "-1";
		return 0;
	}
	int temp2 = 0;
	for (int i = temp; i < n; i++) {
		if (arr[temp - 1] > arr[i]) {
			if (temp2 == 0) {
				temp2 = i;
				continue;
			}
			temp2 = (abs(arr[temp - 1] - arr[i]) < abs(arr[temp - 1] - arr[temp2])) ? i : temp2;
		}
	}
	int temp3 = 0;
	temp3 = arr[temp - 1];
	arr[temp - 1] = arr[temp2];
	arr[temp2] = temp3;
	sort(arr + temp, arr + n, greater<int>());
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}