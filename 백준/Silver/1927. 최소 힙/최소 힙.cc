#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	priority_queue<int,vector<int>,greater<int>> pq;
	vector<int> result;
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		if (num == 0){
			count++;
			if (pq.size() == 0) {
				result.push_back(0);
			}
			else {
				result.push_back(pq.top());
				pq.pop();
			}
		}
		else {
			pq.push(num);
		}
	}
	for (int i = 0; i < count; i++)
	{
		cout << result[i]<<"\n";
	}
}