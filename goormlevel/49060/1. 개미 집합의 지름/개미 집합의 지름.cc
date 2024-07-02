#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int min_removals = n;
    int start = 0;

    for (int end = 0; end < n; end++) {
        while (v[end] - v[start] > d) {
            start++;
        }
        int current_count = end - start + 1;
        min_removals = min(min_removals, n - current_count);
    }

    cout << min_removals << endl;

    return 0;
}
