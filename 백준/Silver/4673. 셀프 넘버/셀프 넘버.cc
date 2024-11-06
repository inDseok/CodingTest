#include <iostream>

using namespace std;
/*
자기자신+첫번쨰+...+마지막
*/

int add_self(int num) {
	int result = num;
	if (num > 0) {
		while (num > 0) {
			result += num % 10;
			num = num / 10;
		}
	}
	return result;
}
int main() {
	int self[10001]={0,};
	self[0] = 1;
	for (int i = 1; i <= 10000; i++) {
		if(add_self(i)<=10000)
			self[add_self(i)] = 1;
	}
	for (int i = 1; i <= 10000; i++) {
		if (self[i] != 1)
			cout << i << endl;
	}
}