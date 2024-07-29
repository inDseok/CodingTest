#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#define INT_MAX 9999999
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};//상 하 좌 우
struct state{
    int y,x,cost,dir;
};
int solution(vector<vector<int>> board) {
    int answer = INT_MAX;
    queue<state> q;
    q.push({0,0,0,-1});
    int size=board.size();
    vector<vector<vector<int>>> cost(size,vector<vector<int>>(size,vector<int>(4,INT_MAX)));
    for (int i = 0; i < 4; i++) {
        cost[0][0][i] = 0;
    }
    while(!q.empty()){
        state cur=q.front();
        q.pop();
        int y=cur.y;
        int x=cur.x;
        int curcost=cur.cost;
        int curdir=cur.dir;
        for(int i=0;i<4;i++){
            int yy=y+dy[i];
            int xx=x+dx[i];
            int nextdir=i;
            if(yy>=0&&yy<size&&xx>=0&&xx<size&&board[yy][xx]==0){
                int nextcost=curcost+100;
                if(curdir!=-1&&curdir!=nextdir){
                    nextcost+=500;
                }
                if(nextcost<cost[yy][xx][nextdir]){
                    cost[yy][xx][nextdir]=nextcost;
                    q.push({yy,xx,nextcost,nextdir});
                }
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        answer = min(answer, cost[size - 1][size - 1][i]);
    }
    return answer;
}