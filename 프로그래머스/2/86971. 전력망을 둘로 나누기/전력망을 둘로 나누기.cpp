#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = 9999999;
    int cnt=0;
    while(cnt<n){
        vector<vector<int>> v(n+1,vector<int>(n+1,0));
        for(int i=0;i<wires.size();i++){
            if(cnt == i) 
                continue;
            int a = wires[i][0];
            int b = wires[i][1];
            v[a][b] = 1;
            v[b][a] = 1;
        }
        vector<bool> visited(n+1,0);
        queue<int> q;
        q.push(1);
        visited[1]=true;
        int cntnode=1;
        while(!q.empty()){
            int now=q.front();
            q.pop();
            for(int i=1;i<=n;i++){
                if(v[now][i]==1&&!visited[i]){
                    visited[i]=true;
                    cntnode++;
                    q.push(i);
                }
            }
        }
        int diff=abs((n-cntnode)-cntnode);
        answer=min(answer,diff);
        cnt++;
    }
    return answer;
}