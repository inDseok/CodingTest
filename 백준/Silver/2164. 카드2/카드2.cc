#include<iostream>
#include<queue>

using namespace std;

int main()
{
	int N;
	cin >> N;
	queue<int> Q;
	for (int i = 1; i <= N; i++)
	{
		Q.push(i);
	}
	while (1)
	{
		if (Q.size() == 1)
			break;
		Q.pop();
		int front = Q.front();
		Q.pop();
		Q.push(front);
	}
	cout << Q.front();
}