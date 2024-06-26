#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    string temp="";
    vector<int> v;
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            v.push_back(stoi(temp));
            temp="";
        }
        else{
            temp+=s[i];
        }
    }
    v.push_back(stoi(temp));
    sort(v.begin(),v.end());
    answer=to_string(v.front())+" ";
    answer+=to_string(v.back());
    return answer;
}