#include <string>
#include <iostream>
#include <set>
using namespace std;
int visited[11][11];
bool chk(int y,int x){
    if(y>=0&&y<=10&&x>=0&&x<=10)
        return true;
    return false;
}
int solution(string dirs) {
    int answer = 0;
    int cur_y = 5, cur_x = 5;
    
    set<pair<pair<int, int>, pair<int, int>>> paths;
    
    for(char dir : dirs) {
        int next_y = cur_y, next_x = cur_x;
        
        switch(dir) {
            case 'U': next_y--; break;
            case 'D': next_y++; break;
            case 'L': next_x--; break;
            case 'R': next_x++; break;
        }
        
        if(chk(next_y, next_x)) {
            pair<int, int> cur = {cur_y, cur_x};
            pair<int, int> next = {next_y, next_x};
            
            if(paths.find({cur, next}) == paths.end() && paths.find({next, cur}) == paths.end()) {
                paths.insert({cur, next});
                paths.insert({next, cur});
                answer++;
            }
            cur_y = next_y;
            cur_x = next_x;
        }
    }
    
    return answer;
}