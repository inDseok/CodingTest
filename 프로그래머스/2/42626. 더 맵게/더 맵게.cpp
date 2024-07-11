#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> pq(scoville.begin(),scoville.end());
    while(pq.top()<K){
        int num1=pq.top();
        pq.pop();
        int num2=pq.top();
        pq.pop();
        int num3=num1+(num2*2);
        pq.push(num3);
        if(pq.size()==1&&num3<K){
            return -1;
        }
        answer++;
    }
    return answer;
}