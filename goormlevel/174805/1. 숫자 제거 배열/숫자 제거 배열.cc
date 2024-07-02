#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	string k;
	cin>>n>>k;
	int cnt=0;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		string ntos;
		ntos=to_string(num);
		if(ntos.find(k)==string::npos)
			cnt++;
	}
	cout<<cnt;
	return 0;
}