#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0;
    int index = 0;
    int total_waiting_time = 0;
    int num_jobs = jobs.size();
    sort(jobs.begin(), jobs.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    while (index < num_jobs || !pq.empty()) {
        while (index < num_jobs && jobs[index][0] <= time) {
            pq.push(make_pair(jobs[index][0], jobs[index][1]));
            index++;
        }

        if (!pq.empty()) {
            int req = pq.top().first;
            int work = pq.top().second;
            pq.pop();
            time += work;
            total_waiting_time += (time - req);
        } else {
            time = jobs[index][0];
        }
    }

    answer = total_waiting_time / num_jobs;
    return answer;
}
