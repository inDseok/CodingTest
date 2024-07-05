#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> s;
    s.insert(words[0]);
    for(int i=1;i<words.size();i++){
        if(words[i][0]!=words[i-1][(int)words[i-1].size()-1]){
            answer.push_back((i + 1) % n == 0 ? n : (i + 1) % n);
            answer.push_back((i + 1 + n - 1) / n);
            break;
        }
        if(s.find(words[i])!=s.end()){
            answer.push_back((i + 1) % n == 0 ? n : (i + 1) % n);
            answer.push_back((i + 1 + n - 1) / n);
            break;
        }
        else{
            s.insert(words[i]);
            continue;
        }
    }
    if(answer.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}