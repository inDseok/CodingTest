#include <iostream>
using namespace std;

int main() {

	long long X, Y, W, S;
	cin >> X >> Y >> W >> S;
	long long answer = 0;
	while (1) {
		if (X == 0 && Y == 0) {
			break;
		}
		if (X > 0 && Y > 0) {
			if ((2 * W) > S) {
				answer = answer + S;
				X--;
				Y--;
			}
			else {
				answer = answer + (2 * W);
				X--;
				Y--;
			}
		}
		else if (X > 0 && Y == 0) {
			if (W > S && X >= 2) {
				X = X - 2;
				answer = answer + (2 * S);
			}
			else {
				answer = answer + W;
				X--;
			}
		}
		else if (Y > 0 && X == 0) {
			if (W > S && Y >= 2) {
				Y = Y - 2;
				answer = answer + (2 * S);
			}
			else {
				answer = answer + W;
				Y--;
			}
		}
	}
	cout << answer;
}