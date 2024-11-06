#include<iostream>

using namespace std;
int N, M;
int arr[9];
int visited[9];
int index = 1;
void print_num(int cnt)
{	
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = 1; i <= N; i++) {
			if (visited[i] == 0) {
				visited[i] = 1;
				arr[cnt] = i;
				print_num(cnt + 1);
				visited[i] = 0;
			}
		}
	}
}
int main()
{
	cin >> N >> M;
	print_num(0);
}