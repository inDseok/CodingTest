#include<iostream>
#include<queue>
using namespace std;
int n, m, r, c, d;
int arr[51][51];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int isvalid()
{
	for (int i = 0; i < 4; i++) {
		if (arr[r + dy[i]][c + dx[i]] == 0) {
			return 1;
			break;
		}
	}
	return 0;
}
int main()
{
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	int cnt = 1;
	arr[r][c] = -1;
	while (1) 
	{
		if (isvalid())
		{
			d = (d + 3) % 4;
			if (arr[r + dy[d]][c + dx[d]] == 0)
			{
				r = r + dy[d];
				c = c + dx[d];
				cnt++;
				arr[r][c] = -1;
			}
			else
				continue;
		}
		else
		{
			if (arr[r + dy[(d + 2) % 4]][c + dx[(d + 2) % 4]] != 1)
			{
				r = r + dy[(d + 2) % 4];
				c = c + dx[(d + 2) % 4];
			}
			else
				break;
		}
	}
	cout << cnt;
}
//110-11-11-8-8-8-5