#include<iostream>
using namespace std;

int main()
{
	int X;
	cin >> X;
	int line=1;
	while (X > line)
	{
		X -= line;
		line++;
	}
	if (line % 2 == 0)
	{
		cout << X << '/' << line - X + 1;
	}
	else 
	{
		cout << line - X + 1 << '/' << X;
	}
}