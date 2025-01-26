#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int cnt;
bool col[16];
bool ldru[32];
bool lurd[32];
void nqueen(int row) {
	if (row == n) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) { //열
		if (col[i])
			continue;
		if (ldru[row + i])
			continue;
		if (lurd[n - i + row - 1])
			continue;
		col[i] = true;
		ldru[row + i] = true;
		lurd[n - i + row - 1] = true;
		nqueen(row + 1);
		/* 백 트래킹 */
		col[i] = false;
		ldru[row + i] = false;
		lurd[n - i + row - 1] = false;
	}
}
int main() {
   cin >> n;
   nqueen(0);
   cout << cnt;
}
