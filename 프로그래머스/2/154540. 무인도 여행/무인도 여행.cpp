#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;
int arr[101][101];
bool visited[101][101];
int row,col;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool is_range(int y,int x){
    return y>=0&&y<row&&x>=0&&x<col;
}
int bfs(int y,int x){
    queue<pair<int,int>> q;
    q.push({y,x});
    int cnt=arr[y][x];
    visited[y][x]=1;
    while(!q.empty()){
        auto cur=q.front();
        q.pop();
        for(int d=0;d<4;d++){
            int yy=cur.first+dy[d];
            int xx=cur.second+dx[d];
            if(!is_range(yy,xx))
                continue;
            if(visited[yy][xx])
                continue;
            if(arr[yy][xx]==-1)
                continue;
            visited[yy][xx]=1;
            cnt+=arr[yy][xx];
            q.push({yy,xx});
        }
    }
    return cnt;
}
vector<int> solution(vector<string> maps) {
    vector<int> answer;
    row=maps.size();
    col=maps[0].size();
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(maps[i][j]=='X')
                arr[i][j]=-1;
            else
                arr[i][j]=maps[i][j]-'0';
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]!=-1&&!visited[i][j]){
                int temp=bfs(i,j);
                answer.push_back(temp);
            }
        }
    }
    if(answer.empty())
        answer.push_back(-1);
    sort(answer.begin(),answer.end());
    return answer;
}