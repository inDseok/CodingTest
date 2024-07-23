#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<vector<string>> tickets;
vector<string> tempPath, bestPath;
vector<bool> visited;
void dfs(string current, int cnt) {
    tempPath.push_back(current);
    if (cnt == tickets.size()) {
        if (bestPath.empty() || tempPath < bestPath) {
            bestPath = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    for (int i = 0; i < tickets.size(); i++) {
        if (!visited[i] && tickets[i][0] == current) {
            visited[i] = true;
            dfs(tickets[i][1], cnt + 1);
            visited[i] = false;
        }
    }
    tempPath.pop_back();
}

vector<string> solution(vector<vector<string>> t) {
    tickets = t;
    sort(tickets.begin(), tickets.end());
    visited.assign(tickets.size(), false);
    dfs("ICN", 0);
    return bestPath;
}
