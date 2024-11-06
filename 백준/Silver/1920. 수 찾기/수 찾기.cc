#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
void bs(int arr[], int start,int end,int num) {
	int mid;
	while (end - start >= 0) {
		mid = (start + end) / 2;
		if (num == arr[mid]) {
			cout << "1" << "\n";
			return;
		}
		else if (num<arr[mid]) {
			end = mid - 1;
		}
		else {
			start = mid+1;
		}
	}
	cout << "0" << "\n";
}
int main() {
	
	cin >> N;
	int arr1[100001];
	int arr2[100001];
	for (int i = 0; i < N; i++) {
		cin >> arr1[i];
	}
	sort(arr1, arr1 + N);
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> arr2[i];
	}
	for (int i = 0; i < M; i++) {
		bs(arr1, 0, N-1, arr2[i]);
	}
}