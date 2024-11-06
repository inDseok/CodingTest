#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
vector<int> v;
int arr[9];
int visited[9];
void print_num(int index,int cnt)
{
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = index; i < N; i++) {
			if (visited[i] == 0) {
				visited[i] = 1;
				arr[cnt] = v[i];
				print_num(i+1,cnt + 1);
				visited[i] = 0;
			}
		}
	}
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	print_num(0,0);
}