#include <string>
#include <vector>
#include <iostream>
using namespace std;
int zero_cnt=0;
int binary_cnt=0;
string tobinary(int n){
    string answer="";
    while(n>0){
        if(n%2==0)
            answer="0"+answer;
        else
            answer="1"+answer;
        n/=2;
    }
    binary_cnt+=1;
    return answer;
}
int count_one(string s){
    int one_cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            one_cnt+=1;
        }
    }
    zero_cnt+=(int)s.size()-one_cnt;
    return one_cnt;
}
vector<int> solution(string s) {
    vector<int> answer;
    int cnt=0;
    while (s != "1") {
        int co = count_one(s);
        s = tobinary(co);
    }
    answer.push_back(binary_cnt);
    answer.push_back(zero_cnt);
    return answer;
}