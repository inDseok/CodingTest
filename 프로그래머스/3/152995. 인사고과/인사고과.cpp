#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
    return a[0] + a[1] > b[0] + b[1];
}

int solution(vector<vector<int>> scores) {
    vector<int> wanho = scores[0];
    sort(scores.begin(), scores.end(), cmp);
    
    int rank = 1;
    int sameRankCount = 0;
    int prevSum = -1;
    
    for (int i = 0; i < scores.size(); i++) {
        bool canGetIncentive = true;
        for (int j = 0; j < scores.size(); j++) {
            if (scores[j][0] > scores[i][0] && scores[j][1] > scores[i][1]) {
                canGetIncentive = false;
                break;
            }
        }
        if (!canGetIncentive) continue;
        
        int sum = scores[i][0] + scores[i][1];
        
        if (sum == prevSum) {
            sameRankCount++;
        } else {
            rank += sameRankCount;
            sameRankCount = 1;
        }

        if (scores[i] == wanho) {
            return rank;
        }

        prevSum = sum;
    }
    return -1;
}
