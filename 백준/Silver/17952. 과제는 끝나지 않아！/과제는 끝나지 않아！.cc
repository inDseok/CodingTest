#include<iostream>
#include<stack>
using namespace std;

int main()
{
	int N;
	cin >> N;
	stack<int> score;
	stack<int> time;
	int result = 0;
	for (int i = 0; i < N; i++)
	{
		int one,A,T;
		cin >> one;
		if (one == 1) {
			cin >> A >> T;
			score.push(A);
			time.push(T);
		}
		if (!time.empty()) {
			time.top()--;
			if (time.top() == 0) {
				result += score.top();
				score.pop();
				time.pop();
			}
		}
	}
	cout << result<<"\n";
}