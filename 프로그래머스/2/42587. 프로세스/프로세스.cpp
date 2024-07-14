#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    for (int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }

    while (!q.empty()) {
        int c_p = q.front().first;
        int c_i = q.front().second;
        q.pop();

        if (c_p == pq.top()) {
            pq.pop();
            answer++;
            if (c_i == location) {
                return answer;
            }
        } else {
            q.push({c_p, c_i});
        }
    }

    return answer;
}