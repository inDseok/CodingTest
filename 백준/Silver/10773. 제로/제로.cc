#include <iostream>
#include<stack>

using namespace std;
int money[100001];
int K;
int index = 0;
void push(int n)
{
	money[index] = n;
	index++;
}
void pop()
{
	money[index] = NULL;
	index--;
}
int main()
{
	cin >> K;
	int num;
	for (int i = 0; i < K; i++) {
		cin >> num;
		if (num != 0)
			push(num);
		else
			pop();
	}
	int sum = 0;
	for (int i = 0; i < index; i++) {
		sum += money[i];
	}
	cout << sum;
}