#include<iostream>
using namespace std;
int N;
int num[12];
int r_max = -1000000000, r_min = 1000000000;
int op[4];
void cal(int result, int index)
{
	if (index == N-1 )
	{
		if (result > r_max)
			r_max = result;
		if (result < r_min)
			r_min = result;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (op[i]) {
			op[i]--;
			switch (i)
			{
			case 0:
				cal(result + num[index + 1], index + 1);
				break;
			case 1:
				cal(result - num[index + 1], index + 1);
				break;
			case 2:
				cal(result * num[index + 1], index + 1);
				break;
			case 3:
				cal(result / num[index + 1], index + 1);
				break;
			}
			op[i]++;
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> op[i];
	}
	cal(num[0], 0);
	cout << r_max << "\n" << r_min;
}