#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
int N, M;
int comb[15];
int arr[51][51];

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				house.push_back({ i,j });
			else if (arr[i][j] == 2)
				chicken.push_back({ i,j });
		}
	}
	int temp = M;
	int cs = chicken.size();
	int result = 10000;
	int k = cs - 1;
	while (temp--) {
		comb[k--] = 1;
	}
	int dist = 0;
	do {
		dist = 0;
		for (int i = 0; i < house.size(); i++)
		{
			int Min = 1000;
			for (int j = 0; j < chicken.size(); j++)
			{
				if (comb[j]) {
					Min = min(Min, abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second));
				}
			}
			dist += Min;
		}
		if (dist < result)
			result = dist;
	} while (next_permutation(comb, comb + cs));
	cout << result;
}