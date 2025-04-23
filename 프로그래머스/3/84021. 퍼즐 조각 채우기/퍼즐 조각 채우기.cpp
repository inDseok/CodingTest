#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
int dy[4]={0,1,0,-1};
int dx[4]={-1,0,1,0};
bool visit[51][51];
bool table_visited[51][51];
int board_size;
vector<vector<pair<int,int>>> dir;
vector<vector<pair<int,int>>> table_dir;
void bfs(int y,int x,vector<vector<int>> game_board,vector<pair<int,int>>& temp,bool visited[51][51],int target){
    queue<pair<int,int>> q;
    visited[y][x]=true;
    temp.push_back({y,x});
    q.push({y,x});
    while(!q.empty()){
        auto cur=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int yy=cur.first+dy[i];
            int xx=cur.second+dx[i];
            if(yy<0||yy>=board_size||xx<0||xx>=board_size||visited[yy][xx])
                continue;
            if(game_board[yy][xx]!=target)
                continue;
            visited[yy][xx]=true;
            temp.push_back({yy,xx});
            q.push({yy,xx});
        }
    }
}
void rotate(vector<vector<int>>& table){
    int n=table.size();
    vector<vector<int>> rotated(n,vector<int>(n));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            rotated[j][n-1-i]=table[i][j];
        }
    }
    table=rotated;
}
void normalize(vector<pair<int,int>> &block){
    int min_y=1e9,min_x=1e9;
    for(auto p:block){
        min_y=min(min_y,p.first);
        min_x=min(min_x,p.second);
    }
    for(auto &p:block){
        p.first-=min_y;
        p.second-=min_x;
    }
    sort(block.begin(),block.end());
}
int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    board_size=game_board.size();
    for(int i=0;i<board_size;i++){
        for(int j=0;j<game_board[i].size();j++){
            if(game_board[i][j]==0&&!visit[i][j]){
                vector<pair<int,int>> temp;
                bfs(i,j,game_board,temp,visit,0);
                normalize(temp);
                dir.push_back(temp);
            }
        }
    }
    for(int i=0;i<dir.size();i++){
        cout << "Block " << i+1 << ":\n";
        for(int j=0;j<dir[i].size();j++){
            cout << dir[i][j].first << " " << dir[i][j].second << "\n";
        }
    cout << "\n";
    }
    for (int d = 0; d < dir.size(); d++) {
        bool matched = false;

        for (int rot = 0; rot < 4; rot++) {
            rotate(table);
            memset(table_visited, 0, sizeof(table_visited));
            table_dir.clear();

            for (int i = 0; i < board_size; i++) {
                for (int j = 0; j < board_size; j++) {
                    if (table[i][j] == 1 && !table_visited[i][j]) {
                        vector<pair<int, int>> temp;
                        bfs(i, j, table, temp, table_visited, 1);  // 절대 좌표 저장

                        vector<pair<int, int>> norm_temp = temp;  // 복사본
                        normalize(norm_temp);
                        table_dir.push_back(norm_temp);

                        // 3. 비교 (정규화된 좌표)
                        if (dir[d] == norm_temp) {
                            answer += norm_temp.size();  // 조각 크기 더하기

                            // 4. 매칭된 조각 table에서 지우기 (절대 좌표로)
                            for (auto p : temp) {
                                table[p.first][p.second] = 0;
                            }

                            matched = true;
                            break;
                        }
                    }
                }
                if (matched) break;
            }
            if (matched) break;
        }
    }
    return answer;
}