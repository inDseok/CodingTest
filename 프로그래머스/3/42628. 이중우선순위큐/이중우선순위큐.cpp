#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;
    for(int i=0;i<operations.size();i++){
        if(operations[i][0]=='I'){
            string s="";
            for(int j=2;j<operations[i].size();j++){
                s+=operations[i][j];
            }
            dq.push_back(stoi(s));
            sort(dq.begin(),dq.end());
        }
        else if(operations[i][0]=='D'){
            if(dq.empty())
                continue;
            
            if(operations[i][2]=='1'){
                dq.pop_back();
            }
            else{
                dq.pop_front();
            }
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