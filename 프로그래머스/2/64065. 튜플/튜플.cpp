#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b){
    return a.second>b.second;
}
vector<int> solution(string s) {
    vector<int> answer;
    map<int,int> m;
    s.erase(s.begin()+1);
    s.erase(s.end()-1);
    string temp="";
    for(int i=0;i<s.size();i++){
        if(s[i]=='{'||s[i]=='}'||s[i]==','){
            if(temp!=""){
                m[stoi(temp)]++;
                temp="";
                continue;
            }
        }
        else{
            temp+=s[i];
        }
    }
    vector<pair<int,int>> v(m.begin(),m.end());
    sort(v.begin(),v.end(),cmp);
    for(auto num : v){
        answer.push_back(num.first);
    }
    return answer;
}