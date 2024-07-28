#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    vector<long long> v1;
    vector<long long> v2;
    int s=-1;
    
    v1.push_back(sequence[0]);
    v2.push_back(sequence[0] * s);
    
    for(int i=1; i<sequence.size(); i++) {
        v1.push_back(max(v1[i-1] + sequence[i] * s, (long long)sequence[i] * s));
        s *= -1;
        v2.push_back(max(v2[i-1] + sequence[i] * s, (long long)sequence[i] * s));
    }
    answer = max(*max_element(v1.begin(), v1.end()), *max_element(v2.begin(), v2.end()));
    
    return answer;
}
