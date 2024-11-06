#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s,i_to_str;
	cin >> s;
	int len, i_len;
	int i = 1;
	int count = 0;
	while (1)
	{
		i_to_str = to_string(i);
		i_len = i_to_str.length();
		for (int j = 0; j < i_len; j++)
		{
			if (s[count] == i_to_str[j])
				count++;
			if (count == s.length()) {
				cout << i;
				return 0;
			}
		}
		i++;
	}
}