#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    vector<int> v(n + 1, 0);
    v[0] = 1;
    
    for(int m : money) {
        for(int i = m; i <= n; ++i) {
            v[i] = (v[i] + v[i - m]) % 1000000007;
        }
    }
    answer=v[n];
    return answer;
}