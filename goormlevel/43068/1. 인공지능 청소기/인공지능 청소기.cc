#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
		int x,y,n;
		cin>>x>>y>>n;
		int sum=abs(x)+abs(y);
	if (n == sum) {
            cout << "YES" << "\n";
        } else if (n < sum) {
            cout << "NO" << "\n";
        } else {
            if ((n - sum) % 2 == 0) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
        }
	}
	return 0;
}