#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n, vector<int> stations, int w){
int answer = 0;
    int current = 1;
    int coverage = 2 * w + 1;

    for (int station : stations) {
        if (current < station - w) {
            int uncovered = (station - w) - current;
            answer += ceil((double)uncovered / coverage);
        }
        current = station + w + 1;
    }

    if (current <= n) {
        int uncovered = n - current + 1;
        answer += ceil((double)uncovered / coverage);
    }

    return answer;
}