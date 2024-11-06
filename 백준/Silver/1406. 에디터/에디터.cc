#include<iostream>
#include<list>
using namespace std;

int main()
{
	string N;
	list<char> l;
	cin >> N;
	for (int i = 0; i < N.size(); i++)
	{
		l.push_back(N[i]);
	}
	int M;
	cin >> M;
	char ins;
	list<char>::iterator l_iter = l.end();
	char command;
	for (int i = 0; i < M; i++)
	{
		cin >> command;
		switch (command)
		{
		case 'L':
			if (l_iter == l.begin())
				break;
			else {
				l_iter--;
				break;
			}
		case 'D':
			if (l_iter == l.end())
				break;
			else {
				l_iter++;
				break;
			}
		case 'B':
			if (l_iter == l.begin()) {
				break;
			}
			else {
				l.erase((--l_iter)++);
				break;
			}
		case 'P':
			char x;
			cin >> x;
			l.insert(l_iter, x);
			break;
		default:
			break;
		}
	}
	for (l_iter = l.begin(); l_iter != l.end(); ++l_iter)
	{
		cout << *l_iter;
	}
}