#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	stack<int> s;
	int num[100001];
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}
	int index = 1;
	int i = 2;
	vector<string> a;
	s.push(1);
	a.push_back("+");
	while(s.size()>=0){
		if (s.size() == 0) {
			if (a.size() == n * 2)
				break;
			s.push(i);
			a.push_back("+");
			i++;
			continue;
		}
		else if (s.top() != num[index]) {
			if (s.top() > num[index])
				break;
			s.push(i);
			a.push_back("+");
			i++;
			continue;
		}
		else if (s.top() == num[index]) {
			s.pop();
			a.push_back("-");
			index++;
			continue;
		}
	}
	if (a.size()==n*2) {
		for (int k = 0; k < a.size(); k++) {
			cout << a[k] << "\n";
		}
	}
	else {
		cout << "NO";
	}

}