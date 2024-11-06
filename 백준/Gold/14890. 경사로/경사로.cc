#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int arr[101][101];
int main() {
	int n,l;
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	int result=0;
	for (int i = 0; i < n; i++) {
		int check = 1;
		bool visit = false;
		for (int j = 0; j < n - 1; j++) {
			if (arr[i][j] == arr[i][j + 1]) {
				check++;
				visit = true;
			}
			else if (arr[i][j] + 1 == arr[i][j + 1] && check >= l) {
				check = 1;
				visit = true;
			}
			else if (arr[i][j] == arr[i][j + 1]+1 && check >= 0) {
				check = 1-l;
				visit = true;
			}
			else {
				visit = false;
			}
			if (!visit)
				break;
		}
		if (visit && check >= 0)
			result++;
	}
	for (int i = 0; i < n; i++) {
		int check = 1;
		bool visit = false;
		for (int j = 0; j < n - 1; j++) {
			if (arr[j][i] == arr[j+1][i]) {
				check++;
				visit = true;
			}
			else if (arr[j][i] + 1 == arr[j+1][i] && check >= l) {
				check = 1;
				visit = true;
			}
			else if (arr[j][i] == arr[j+1][i] + 1 && check >= 0) {
				check = 1 - l;
				visit = true;
			}
			else {
				visit = false;
			}
			if (!visit)
				break;
		}
		if (visit && check >= 0)
			result++;
	}
	cout << result;
}