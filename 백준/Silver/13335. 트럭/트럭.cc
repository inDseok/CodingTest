#include<iostream>
#include<queue>
using namespace std;
int n, w, l;
queue<int> q;
int arr[1001];
int main()
{
	int sum = 0;
	int time = 0;
	cin >> n >> w >> l;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		while (1) {
			if (q.size() == w) {
				sum -= q.front();
				q.pop();
			}
			if (sum + arr[i] <= l)
				break;
			q.push(0);
			time++;
		}
		q.push(arr[i]);
		sum += arr[i];
		time++;
	}
	time+=w;
	cout << time;
}