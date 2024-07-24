#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
string change(int a,int k){
    vector<int> v;
    while(a>0){
        int temp=a%k;
        v.push_back(temp);
        a=a/k;
    }
    string result="";
    for(int i=v.size()-1;i>=0;i--){
        result+=to_string(v[i]);
    }
    return result;
}
bool isPrime(long long a){
    if(a<=1){
        return false;
    }
    int t=sqrt(a);
    for(int i=2;i<=t;i++){
        if(a%i==0){
            return false;
            break;
        }
    }
    return true;
}
int solution(int n, int k) {
    int answer = 0;
    string num=change(n,k);
    string temp="";
    for(int i=0;i<num.size();i++){
        if (num[i] != '0') {
            temp += num[i];
        } 
        else {
            if (!temp.empty()) {
                long long t = stoll(temp);
                if (isPrime(t))
                    answer++;
                temp.clear();
            }
        }
    }
    if (!temp.empty()) {
        long long t = stoll(temp);
        if (isPrime(t))
            answer++;
    }
    return answer;
}