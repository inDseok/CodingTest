#include<iostream>

using namespace std;
int N, M, B;
int g[502][502];
int mintime = 100000000;
int maxheight = 0;

int main()
{
	cin >> N >> M >> B;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> g[i][j];
		}
	}

	for (int h = 0; h <= 256; h++)
	{
		int build = 0;
		int dig = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int ch = g[i][j] - h;
				if (ch < 0)
					build -= ch;
				else
					dig += ch;
			}
		}
		if (dig + B >= build) {
			int time = 2 * dig + build;
			if (mintime >= time) {
				mintime = time;
				maxheight = h;
			}
		}
	}
	cout << mintime << " " << maxheight;
}