#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(string s : skill_trees){
        string temp="";
        bool chk=true;
        for(int i=0;i<s.size();i++){
            if(find(skill.begin(),skill.end(),s[i])!=skill.end()){
                temp+=s[i];
            }
            for(int j=0;j<temp.size();j++){
                if(temp[j]!=skill[j])
                    chk=false;
            }
        }
        if(chk)
                answer++;
    }
    return answer;
}