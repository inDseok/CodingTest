#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<vector<int>> arr(n+1);
    for(auto it : roads) {
        arr[it[0]].push_back(it[1]);
        arr[it[1]].push_back(it[0]);
    }
    vector<int> dist(n+1, -1);
    queue<int> q;
    q.push(destination);
    dist[destination] = 0;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(int next : arr[curr]) {
            if(dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }

    for(int src : sources) {
        answer.push_back(dist[src]);
    }

    return answer;
}
