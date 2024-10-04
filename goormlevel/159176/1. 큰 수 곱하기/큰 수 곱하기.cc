#include <iostream>
using namespace std;
int main() {
	string s="1";
	for(int i=0;i<10;i++){
		int hund;
		cin>>hund;
		if(hund==100){
			s+="00";
		}
	}
	cout<<s;
}