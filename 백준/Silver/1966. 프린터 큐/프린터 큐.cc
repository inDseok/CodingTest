#include<iostream>
#include<queue>
#include<algorithm>
#include <tuple>
using namespace std;

int main()
{
	int T;
	cin >> T;
	
	while (T--) {
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		int N, M;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			int ip;
			cin >> ip;
			pq.push(ip);
			q.push({ i,ip });
		}
		
		int result = 0;
		int k, v;
		while (!q.empty())
		{
			tie(k, v) = q.front();
			q.pop();
			if (pq.top() == v) {
				pq.pop();
				result++;
				if (k == M)
				{
					cout << result << "\n";
					break;
				}
			}
			else
				q.push({ k,v });
		}
	}
}