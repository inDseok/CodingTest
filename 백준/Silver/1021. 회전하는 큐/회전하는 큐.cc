#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

deque<int> dq;
void left()
{
	dq.push_back(dq.front());
	dq.pop_front();
}
void right()
{
	dq.push_front(dq.back());
	dq.pop_back();
}
int main()
{
	int N,M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		dq.push_back(i);
	}
	int arr[50];
	for (int i = 0; i < M; i++)
	{
		cin >> arr[i];
	}
	int count = 0;
	for (int i = 0; i < M; i++)
	{
		deque<int>::iterator dq_iter;
		dq_iter = find(dq.begin(), dq.end(), arr[i]);
		if (dq.front() == arr[i]) {
			dq.pop_front();
			continue;
		}
		else if (dq_iter - dq.begin() > dq.size() / 2) {
			while (1)
			{
				if (dq.front() == arr[i]) {
					dq.pop_front();
					break;
				}
				right();
				count++;
			}
		}
		else if (dq_iter - dq.begin() <= dq.size() / 2) {
			while (1)
			{
				if (dq.front() == arr[i]) {
					dq.pop_front();
					break;
				}
				left();
				count++;
			}
		}
	}
	cout << count;
}