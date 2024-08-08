#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    int sum=0;
    int idx=0;
    while(1){
        if(idx==truck_weights.size()){
            answer+=bridge_length;
            break;
        }
        answer++;
        if(q.size()==bridge_length){
            sum-=q.front();
            q.pop();
        }
        if(sum+truck_weights[idx]<=weight){
            sum+=truck_weights[idx];
            q.push(truck_weights[idx]);
            idx++;
        }
        else{
            q.push(0);
        }
    }
    return answer;
}