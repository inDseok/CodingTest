#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    for(int i=0;i<works.size();i++){
        pq.push(works[i]);
    }
    while(n>0){
        if(pq.top()==0)
            break;
        n--;
        int num=pq.top();
        pq.pop();
        num=num-1;
        pq.push(num);
    }
    while(!pq.empty()){
        int t=pq.top();
        pq.pop();
        answer+=t*t;
    }
    return answer;
}