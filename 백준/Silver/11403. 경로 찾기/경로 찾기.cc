#include<iostream>

using namespace std;
int n;
int arr[105][105];
void floyd()
{
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][k] && arr[k][j])
					arr[i][j] = 1;
			}
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	floyd();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] <<" ";
		}
		cout << "\n";
	}
}