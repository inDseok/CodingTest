#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}
	int arr[51]={0,};
	for (int i = 0; i < N; i++)
	{
		int count = 1;
		for (int j = 0; j < N; j++)
		{
			if (v[i].first < v[j].first && v[i].second < v[j].second) {
				count++;
			}
		}
		arr[i] = count;
	}
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << "\n";
	}
}