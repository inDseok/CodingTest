#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    queue<int> q;
    for(int i=1;i<=order.size();i++){
        q.push(i);
    }
    int idx=0;
    stack<int> s;
    while(1){
        if(!q.empty()&&order[idx]==q.front()){
            answer++;
            q.pop();
            idx++;
        }
        else if(!s.empty()&&order[idx]==s.top()){
            answer++;
            s.pop();
            idx++;
        }
        else if(!q.empty()){
            s.push(q.front());
            q.pop();
        }
        else{
            break;
        }
    }
    return answer;
}