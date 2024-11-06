#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	stack<int> sta;
	for (int i = 0; i < N; i++)
	{
		string order;
		int num;
		cin >> order;
		if (order.compare("push")==0)
		{
			cin >> num;
			sta.push(num);
		}
		else if (order.compare("pop") == 0)
		{
			if (!sta.empty()) {
				cout << sta.top() << "\n";
				sta.pop();
			}
			else {
				cout << "-1"<<"\n";
			}
		}
		else if (order.compare("size") == 0)
		{
			cout << sta.size() << "\n";
		}
		else if (order.compare("empty") == 0)
		{
			if (!sta.empty()) {
				cout << "0" << "\n";
			}
			else {
				cout << "1" << "\n";
			}
		}
		else if (order.compare("top") == 0)
		{
			if (!sta.empty()) {
				cout << sta.top() << "\n";
			}
			else {
				cout << "-1" << "\n";
			}
		}
	}
}