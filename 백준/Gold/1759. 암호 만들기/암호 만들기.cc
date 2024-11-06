#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int L, C;
vector<char> v;
vector<char> result;
int visited[16];
vector<char>::iterator iter;
vector<char> vowels = { 'a', 'e', 'i', 'o', 'u' };

void dfs(int index,int cnt)
{
	int ja = 0, mo = 0;
	if (result.size() == L) {
		for (int j=0;j<result.size();j++){
			if (result[j] == 'a' || result[j] == 'e' || result[j] == 'i' || result[j] == 'o' || result[j] == 'u')
				ja++;
			else
				mo++;
		}
		if (ja>=1&&mo>=2) {
			for (int i = 0; i < result.size(); i++) {
				cout << result[i];
			}
			cout << "\n";
		}
		ja = 0;
		mo = 0;
	}
	else {
		for (int i = index; i < C; i++) {
			if (visited[i] == 0) {
				visited[i] = 1;
				result.push_back(v[i]);
				dfs(i, cnt + 1);
				result.pop_back();
				visited[i] = 0;
			}
		}
	}
}
int main()
{
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		char alpha;
		cin >> alpha;
		v.push_back(alpha);
	}
	sort(v.begin(), v.end());
	dfs(0,0);
}