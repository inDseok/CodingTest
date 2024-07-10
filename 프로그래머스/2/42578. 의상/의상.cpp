#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string,vector<string>> m;
    for(int i=0;i<clothes.size();i++){
        m[clothes[i][1]].push_back(clothes[i][0]);
    }
    
    for(auto iter : m){
        answer*=(m[iter.first].size()+1);
    }
    answer--;
    return answer;
}