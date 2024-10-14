#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int arr[201][201];
int dist[201][201];
void dijkstra(int start,int n){
    for (int i = 1; i <= n; i++) {
        dist[start][i] = 1e9;
    }
    dist[start][start]=0;
    priority_queue<pair<int,int>> pq;
    pq.push({0,start});
    while(!pq.empty()){
        auto cur=pq.top();
        pq.pop();
        int curdist=cur.first*-1;
        int curnode=cur.second;
        if(dist[start][curnode]<curdist)
            continue;
        for(int i=1;i<=n;i++){
            if(arr[curnode][i]==0)
                continue;
            int nextdist=curdist+arr[curnode][i];
            int nextnode=i;
            if(dist[start][nextnode]>nextdist){
                dist[start][nextnode]=nextdist;
                pq.push({-nextdist,nextnode});
            }
        }
    }
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    
    for(int i=0;i<fares.size();i++){
        arr[fares[i][0]][fares[i][1]]=fares[i][2];
        arr[fares[i][1]][fares[i][0]]=fares[i][2];
    }
    dijkstra(s,n);
    dijkstra(a,n);
    dijkstra(b,n);
    int answer=999999999;
    for(int i=1;i<=n;i++){
        if (dist[s][i] == 1e9 || dist[a][i] == 1e9 || dist[b][i] == 1e9)
            continue;

        int currentdist=dist[s][i]+dist[a][i]+dist[b][i];
        answer=min(answer,currentdist);
    }
    return answer;
}