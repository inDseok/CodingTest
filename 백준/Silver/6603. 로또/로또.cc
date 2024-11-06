#include<iostream>

using namespace std;
int k;
int arr[50];
int result[50];
int visited[50];
void print_num(int index,int cnt)
{
	if (cnt == 6) {
		for (int i = 0; i < 6; i++) {
			cout << result[i]<<" ";
		}
		cout << "\n";
	}
	else {
		for (int i = index; i < k; i++) {
			if (visited[i] == 0) {
				visited[i] = 1;
				result[cnt] = arr[i];
				print_num(i+1,cnt + 1);
				visited[i] = 0;
			}
		}
	}
}
int main()
{
	
	while (1)
	{
		cin >> k;
		if (k == 0)
			break;
		for (int i = 0; i < k; i++)
		{
			cin >> arr[i];
		}
		print_num(0,0);
		cout << "\n";
	}
}