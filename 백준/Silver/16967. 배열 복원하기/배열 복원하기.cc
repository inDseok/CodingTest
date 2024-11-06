#include<iostream>
using namespace std;

int arr[700][700];
int main()
{
	int H, W, X, Y;
	cin >> H >> W >> X >> Y;
	
	for (int i = 0; i < H + X; i++)
	{
		for (int j = 0; j < W + Y; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++) {
			if (i < X || j < Y) {
				arr[i][j] = arr[i][j];
			}
			else {
				arr[i][j] = arr[i][j] - arr[i - X][j - Y];
			}
		}
	}
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++) {
			cout << arr[i][j]<<" ";
		}
		cout << "\n";
	}
}