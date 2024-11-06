#include <iostream>
#include <map>
using namespace std;

int main()
{
	int n;
	cin >> n;
	map<long long, int> m;
	long long num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		m[num]++;
	}
	int max = 0;
	long long index = 0;
	for (auto i = m.begin(); i != m.end(); i++)
	{
		if (i->second > max) {
			max = i->second;
			index = i->first;
		}
		if (i->second == max && i->first < index) {
			max = i->second;
			index = i->first;
		}
	}
	cout << index << "\n";
}