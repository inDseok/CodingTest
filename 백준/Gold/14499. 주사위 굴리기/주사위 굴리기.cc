#include<iostream>

using namespace std;
int n, m;
int x, y;
int k;
int arr[21][21]={-1,};
int dice[6]={0,};
//동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4
//밑 0, 위 1, 왼 2, 오른 3, 앞 4, 뒤 5
int main()
{
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < k; i++)
	{
		int dir;
		cin >> dir;
		switch (dir)
		{
		case 1:
		{
			if (y+1 >= m)
				continue;
			y ++;
			int temp;
			temp = dice[0];
			dice[0] = dice[3];
			dice[3] = dice[1];
			dice[1] = dice[2];
			dice[2] = temp;
			if (arr[x][y]) {
				dice[0] = arr[x][y];
				arr[x][y] = 0;
			}
			else
				arr[x][y] = dice[0];
			cout << dice[1] << "\n";
			break;
		}
		case 2:
		{
			if (y - 1 < 0)
				continue;
			y --;
			int temp;
			temp = dice[0];
			dice[0] = dice[2];
			dice[2] = dice[1];
			dice[1] = dice[3];
			dice[3] = temp;
			if (arr[x][y]) {
				dice[0] = arr[x][y];
				arr[x][y] = 0;
			}
			else
				arr[x][y] = dice[0];
			cout << dice[1]<<"\n";
			break;
		}
		case 3:
		{
			if (x - 1 < 0)
				continue;
			x --;
			int temp;
			temp = dice[0];
			dice[0] = dice[5];
			dice[5] = dice[1];
			dice[1] = dice[4];
			dice[4] = temp;
			if (arr[x][y]) {
				dice[0] = arr[x][y];
				arr[x][y] = 0;
			}
			else
				arr[x][y] = dice[0];
			cout << dice[1] << "\n";
			break;
		}
		case 4:
		{
			if (x + 1 >= n)
				continue;
			x ++;
			int temp;
			temp = dice[0];
			dice[0] = dice[4];
			dice[4] = dice[1];
			dice[1] = dice[5];
			dice[5] = temp;
			if (arr[x][y]) {
				dice[0] = arr[x][y];
				arr[x][y] = 0;
			}
			else
				arr[x][y] = dice[0];
			cout << dice[1] << "\n";
			break;
		}
		default:
			break;
		}
	}
}