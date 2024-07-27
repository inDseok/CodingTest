#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
string s="0123456789ABCDEF";
string change(int a,int n){
    string temp="";
    while(a>0){
        temp+=s[a%n];
        a/=n;
    }
    reverse(temp.begin(),temp.end());
    return temp;
}
string solution(int n, int t, int m, int p) {
    string answer = "";
    string temp="0";
    for(int i=0;temp.size()<t*m;i++){
        temp+=change(i,n);
    }
    for(int i=p-1;i<t*m;i+=m){
        answer+=temp[i];
    }
    return answer;
}