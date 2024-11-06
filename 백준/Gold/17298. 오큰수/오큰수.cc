#include <iostream>
#include <stack>
using namespace std;

int arr[1000001];
int ans[1000001];
int main()
{
	int N;
	cin >> N;
	stack<int> s;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int j = N - 1; j >= 0; j--)
	{
		while (!s.empty() && s.top() <= arr[j])
			s.pop();
		if (s.empty())
			ans[j] = -1;
		else
			ans[j] = s.top();

		s.push(arr[j]);
	}
	for (int i = 0; i < N; i++)
	{
		cout << ans[i]<<" ";
	}
}