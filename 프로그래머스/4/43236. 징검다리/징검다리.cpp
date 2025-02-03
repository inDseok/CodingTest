#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    rocks.push_back(distance);
    sort(rocks.begin(),rocks.end());
    
    int begin=1;
    int end=distance;
    
    while(begin<=end){
        int prev_rock=0;
        int remove_cnt=0;
        int max_diff=(begin+end)/2;
        
        for(auto rock :rocks){
            if(rock-prev_rock<max_diff)
                remove_cnt++;
            else
                prev_rock=rock;
        }
        if(remove_cnt<=n){
            answer=max(max_diff,answer);
            begin=max_diff+1;
        }
        else
            end=max_diff-1;
    }
    return answer;
}