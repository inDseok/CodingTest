#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
string s1, s2;
int arr[4001][4001]={0,};
int m = 0;
int main()
{
	cin >> s1 >> s2;
	
	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			if (s1[i-1] == s2[j-1]) {
				arr[i][j] = arr[i - 1][j - 1] + 1;
				if (arr[i][j] > m)
					m = arr[i][j];
			}
		}
	}
	cout << m;
}