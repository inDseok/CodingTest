#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(string a,string b){
    return a+b>b+a;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for(int num:numbers)
        v.push_back(to_string(num));
    sort(v.begin(),v.end(),cmp);
    if(v[0]=="0"&&v[v.size()-1]=="0"){
        answer="0";
        return answer;
    }
    for(int i=0;i<v.size();i++){
        answer+=v[i];
    }
    return answer;
}