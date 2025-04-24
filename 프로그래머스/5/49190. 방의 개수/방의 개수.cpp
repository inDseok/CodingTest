#include <string>
#include <vector>
#include <map>

using namespace std;

int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,1,1,1,0,-1,-1,-1};

int solution(vector<int> arrows) {
    int answer = 0;
    map<pair<int,int>,bool> Node_visit;
    map<pair<pair<int,int>,pair<int,int>>,bool> Edge_visit;
    
    int y=0;
    int x=0;
    Node_visit[{y,x}]=true;
    for(int i=0;i<arrows.size();i++){
        int dir=arrows[i];
        for(int j=0;j<2;j++){
            int ny=y+dy[dir];
            int nx=x+dx[dir];
            
            if(Node_visit[{ny,nx}]==true&&Edge_visit[{{y,x},{ny,nx}}]==false){
                Edge_visit[{{y,x},{ny,nx}}]=true;
                Edge_visit[{{ny,nx},{y,x}}]=true;
                
                answer++;
                y=ny;
                x=nx;
                continue;
            }
            Node_visit[{ny,nx}]=true;
            Edge_visit[{{y,x},{ny,nx}}]=true;
            Edge_visit[{{ny,nx},{y,x}}]=true;
            
            y=ny;
            x=nx;
        }
    }
    return answer;
}