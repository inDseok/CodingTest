#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;
    for(int i=0;i<operations.size();i++){
        if(operations[i][0]=='I'){
            string temp="";
            for(int j=2;j<operations[i].size();j++){
                temp+=operations[i][j];
            }
            dq.push_back(stoi(temp));
            sort(dq.begin(),dq.end());
        }
        else if(operations[i][0]=='D'&&!dq.empty()){
            if(operations[i][2]=='1')
                dq.pop_back();
            else 
                dq.pop_front();
        }
    }
    if(dq.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }
    return answer;
}