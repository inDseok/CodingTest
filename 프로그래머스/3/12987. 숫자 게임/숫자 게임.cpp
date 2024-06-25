#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(),A.end());
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<B.size();i++){
        pq.push(B[i]);
    }
    int i=0;
    while(!pq.empty()){
        if(A[i]<pq.top()){
            answer++;
            pq.pop();
            i++;
        }
        else{
            pq.pop();
        }
    }
    return answer;
}