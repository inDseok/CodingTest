#include<iostream>
#include<string>
using namespace std;
string a,b;
int ctoi[101];
int ston(string s)
{
	int an = 0;
	for (int i = 0; i < s.length(); i++) {
		if (i + 1 < s.length()) {
			if (s[i] == 'I' && s[i + 1] == 'V') {
				an += 4;
				i++;
				continue;
			}
			if (s[i] == 'I' && s[i + 1] == 'X') {
				an += 9;
				i++;
				continue;
			}
			if (s[i] == 'X' && s[i + 1] == 'L') {
				an += 40;
				i++;
				continue;
			}
			if (s[i] == 'X' && s[i + 1] == 'C') {
				an += 90;
				i++;
				continue;
			}
			if (s[i] == 'C' && s[i + 1] == 'D') {
				an += 400;
				i++;
				continue;
			}
			if (s[i] == 'C' && s[i + 1] == 'M') {
				an += 900;
				i++;
				continue;
			}
		}
		an += ctoi[s[i]];
	}
	return an;
}
string ntos(int n)
{
	string result="";
	while (n > 0) {
		if (n >= 1000) {
			result += "M";
			n -= 1000;
		}
		else if (n >= 900) {
			result += "CM";
			n -= 900;
		}
		else if (n >= 500) {
			result += "D";
			n -= 500;
		}
		else if (n >= 400) {
			result += "CD";
			n -= 400;
		}
		else if (n >= 100) {
			result += "C";
			n -= 100;
		}
		else if (n >= 90) {
			result += "XC";
			n -= 90;
		}
		else if (n >= 50) {
			result += "L";
			n -= 50;
		}
		else if (n >= 40) {
			result += "XL";
			n -= 40;
		}
		else if (n >= 10) {
			result += "X";
			n -= 10;
		}
		else if (n >= 9) {
			result += "IX";
			n -= 9;
		}
		else if (n >= 5) {
			result += "V";
			n -= 5;
		}
		else if (n ==4) {
			result += "IV";
			n -= 4;
		}
		else if (n >= 1) {
			result += "I";
			n -= 1;
		}
	}
	return result;
}
int main()
{
	cin >> a >> b;
	ctoi['I'] = 1;
	ctoi['V'] = 5;
	ctoi['X'] = 10;
	ctoi['L'] = 50;
	ctoi['C'] = 100;
	ctoi['D'] = 500;
	ctoi['M'] = 1000;
	int sum = ston(a) + ston(b);
	cout << sum << "\n";
	cout << ntos(sum);
}