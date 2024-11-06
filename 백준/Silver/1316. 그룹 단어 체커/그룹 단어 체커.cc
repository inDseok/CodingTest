#include<iostream>
#include<set>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int result = 0;
	while (N--)
	{
		set<char> sc;
		string s;
		cin >> s;
		int temp = 0;
		for (int i = 0; i < s.length(); i++)
		{
			sc.insert(s[i]);
			if (s[i] != s[i + 1])
			{
				temp += 1;
			}
		}
		if (temp <= sc.size())
			result++;
	}
	cout << result << "\n";
}