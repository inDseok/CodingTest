#include<iostream>
#include<stack>
using namespace std;
int N, M;
int arr[9];
void print_num(int num,int cnt)
{
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = num; i <= N; i++) {
			arr[cnt] = i;
			print_num(i+1,cnt + 1);
		}
	}
}
int main()
{
	cin >> N >> M;
	print_num(1,0);
}