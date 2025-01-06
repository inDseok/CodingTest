#include<iostream>
#include <vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[8001]={0};
	vector<int> v;
	double mean=0;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr[num + 4000]++;
		v.push_back(num);
		mean += num;
	}
	mean = (round(mean / n)==0)?0:round(mean/n);
	cout << mean << "\n";

	sort(v.begin(), v.end());
	cout << v[n / 2]<<"\n";

	vector<int> many;
	int max = *max_element(arr, arr + 8001);
	for (int i = 0; i < 8001; i++) {
		if (arr[i] == max)
			many.push_back(i-4000);
	}
	if (many.size() > 1) {
		cout << many[1] << "\n";
	}
	else {
		cout << many[0] << "\n";
	}
	cout << v[n - 1] - v[0]<<"\n";
}