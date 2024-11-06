#include<iostream>
#include<algorithm>
using namespace std;
char arr[51][51];
int N;
int cnt;
int candy=1;
void check()
{
	for (int i = 1; i <= N; i++) {
		cnt = 1;
		for (int j = 1; j <= N - 1; j++) {
			if (arr[i][j] == arr[i][j + 1]) {
				cnt++;
				if (cnt > candy)
					candy = cnt;
			}
			else
				cnt = 1;
		}
	}
	for (int i = 1; i <= N; i++) {
		cnt = 1;
		for (int j = 1; j <= N - 1; j++) {
			if (arr[j][i] == arr[j+1][i]) {
				cnt++;
				if (cnt > candy)
					candy = cnt;
			}
			else
				cnt = 1;
		}
	}
}
int main()
{
	cin >> N;
	//C 빨간색,P 초록색, Z 초록색, Y 노란색
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N-1; j++) {
			swap(arr[i][j], arr[i][j + 1]);
			check();
			swap(arr[i][j+1], arr[i][j]);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N-1; j++) {
			swap(arr[j][i], arr[j+1][i]);
			check();
			swap(arr[j+1][i], arr[j][i]);
		}
	}
	cout << candy;
}