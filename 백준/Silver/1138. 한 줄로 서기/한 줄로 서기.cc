#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N;
	int p[12];
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> p[i];
	}
	vector<int>v;
	for (int i = N-1; i >= 0; i--)
	{
		vector<int>::iterator iter = v.begin();
		for (int j = 0; j < p[i]; j++) {
			iter++;
		}
		v.insert(iter, i + 1);
	}
	for (int j = 0; j < v.size(); j++) {
		cout << v[j] << " ";
	}
}