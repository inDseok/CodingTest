#include<iostream>
#include<stack>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int k=0;k<T;k++)
	{
		string ps;
		cin >> ps;
		stack<char> str;
		for (int i = 0; i < ps.length(); i++)
		{
			if (ps[i] == '(')
			{
				str.push(ps[i]);
			}
			else if (ps[i] == ')')
			{
				if(str.empty()||str.top()==')')
				{
					str.push(ps[i]);
				}
				else
				{
					str.pop();
				}
			}
		}
		if (!str.empty())
		{
			cout << "NO"<<"\n";
		}
		else
		{
			cout << "YES"<<"\n";
		}
	}
}