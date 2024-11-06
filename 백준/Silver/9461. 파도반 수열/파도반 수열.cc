#include<iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	long long arr[101];
	arr[0] = 0 ;
	for (int i = 1; i <= 3; i++)
	{
		arr[i] = 1;
	}
	while (T--) {
		int N;
		cin >> N;
		for (int j = 4; j <= N; j++) {
			arr[j] = arr[j - 2] + arr[j - 3];
		}
		cout << arr[N]<<"\n";
	}

}