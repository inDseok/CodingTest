#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int main()
{
	int arr[4][8];
	int rotate[4]= { 0 };;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	int k;
	cin >> k;
	while (k--) {
		int num, dir;
		cin >> num >> dir;
		num--;
		rotate[num] = dir;
		int temp_dir = dir;
		for (int i = num - 1; i >= 0; i--) {
			temp_dir *= -1;
			if (arr[i][2] != arr[i+1][6]) {
				rotate[i] = temp_dir;
			}
			else
				break;
		}
		temp_dir = dir;
		for (int i = num + 1; i < 4; i++) {
			temp_dir *= -1;
			if (arr[i][6] != arr[i-1][2]) {
				rotate[i] = temp_dir;
			}
			else
				break;
		}
		int temp ;
		for (int i = 0; i < 4; i++) {
			if (rotate[i] == 1) {
				temp = arr[i][7];
				for (int j= 7; j > 0; j--) {
					arr[i][j] = arr[i][j - 1];
				}
				arr[i][0] = temp;
			}
			else if (rotate[i] == -1) {
				temp = arr[i][0];
				for (int j = 0; j < 7; j++) {
					arr[i][j] = arr[i][j +1];
				}
				arr[i][7] = temp;
			}
		}
		for (int i = 0; i < 4; i++) {
			rotate[i] = 0;
		}
	}
	int result = 0;
	if (arr[0][0])
		result += 1;
	if (arr[1][0])
		result += 2;
	if (arr[2][0])
		result += 4;
	if (arr[3][0])
		result += 8;
	cout << result;
	return 0;
}