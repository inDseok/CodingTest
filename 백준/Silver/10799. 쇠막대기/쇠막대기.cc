#include<iostream>
#include<stack>
using namespace std;

int main()
{
	string stick;
	cin >> stick;
	stack<char> cnum;
	int result = 0;
	for (int i = 0; i < stick.size(); i++)
	{
		if (stick[i] == '(') 
		{
			cnum.push(stick[i]);
		}
		else if (stick[i] == ')' && stick[i - 1] == '(')
		{
			cnum.pop();
			result += cnum.size();
		}
		else if (stick[i] == ')')
		{
			cnum.pop();
			result++;
		}
		if (cnum.empty()) {
		}
	}
	cout << result;
}