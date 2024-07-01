#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;
vector<string> ui,bi;
vector<bool> visited(8,false);
unordered_set<string> us;
void dfs(int idx,vector<int>& selected){
    if(idx==bi.size()){
        vector<int> sorted = selected;
        sort(sorted.begin(), sorted.end());
        string combination = "";
        for (int i : sorted) {
            combination += to_string(i) + ",";
        }
        if (us.find(combination) == us.end()) {
            us.insert(combination);
        }
        return;
    }
    for(int i=0;i<ui.size();i++){
        if (visited[i]) 
            continue;
        bool same=true;
        string s1=ui[i];
        string s2=bi[idx];
        if(s1.size()!=s2.size())
            continue;
        for(int j=0;j<s1.size();j++){
            if(s2[j]=='*')
                continue;
            if(s1[j]!=s2[j]){
                same=false;
                break;
            }
        }
        if(same){
                visited[i]=true;
                selected.push_back(i);
                dfs(idx+1,selected);
                selected.pop_back();
                visited[i]=false;
        }
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer=0;
    ui=user_id;
    bi=banned_id;
    vector<int> selected;
    dfs(0,selected);
    answer=us.size();
    return answer;
}