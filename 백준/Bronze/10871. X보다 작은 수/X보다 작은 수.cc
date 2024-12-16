#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num < x)
            v.push_back(num);
    }
    for (int j = 0; j < v.size(); j++) {
        cout << v[j] << " ";
    }
    return 0;
}
