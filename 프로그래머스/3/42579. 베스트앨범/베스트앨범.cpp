#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
bool cmp(pair<string,int> a,pair<string,int> b){
    return a.second>b.second;
}
bool cmp2(pair<int,int> a,pair<int,int> b){
    if (a.first == b.first) 
        return a.second < b.second;
    return a.first > b.first;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,int> m;
    map<string, vector<pair<int, int>>> v;
    for(int i=0;i<genres.size();i++){
        m[genres[i]]+=plays[i];
        v[genres[i]].push_back({plays[i],i});
    }
    vector<pair<string, int>> v2(m.begin(), m.end());
    sort(v2.begin(),v2.end(),cmp);
    for(int i=0;i<v2.size();i++){
        string g=v2[i].first;
        vector<pair<int,int>> v3=v[g];
        sort(v3.begin(),v3.end(),cmp2);
         for (int j = 0; j < min(2, (int)v3.size()); j++) {
            answer.push_back(v3[j].second);
        }
    }
    return answer;
}