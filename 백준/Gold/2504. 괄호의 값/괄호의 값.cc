#include<iostream>
#include<stack>
using namespace std;
int main()
{
	string c;
	cin >> c;
	stack<char> s;
	int result = 0;
	int temp = 1;
	bool valid = true;
	for (int i = 0; i < c.length(); i++)
	{
		switch (c[i])
		{
		case '(':
			temp *= 2;
			s.push(c[i]);
			break;
		case ')':
			if (s.empty() || s.top() != '(') {
				valid = false;
				break;
			}
			else if (c[i - 1] == '(') {
				result += temp;
				temp /= 2;
				s.pop();
				break;
			}
			else {
				temp /= 2;
				s.pop();
				break;
			}
		case '[':
			temp *= 3;
			s.push(c[i]);
			break;
		case ']':
			if (s.empty() || s.top() != '[') {
				valid = false;
				break;
			}
			else if (c[i - 1] == '[') {
				result += temp;
				temp /= 3;
				s.pop();
				break;
			}
			else {
				temp /= 3;
				s.pop();
				break;
			}
		}
	}
	if (!s.empty()||!valid)
		result = 0;
	cout << result<<"\n";
}