#include <string>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
string change(string s){
    string result="";
    for(char c : s){
        result+=tolower(c);   
    }
    return result;
}
int solution(string str1, string str2) {
    int answer = 0;
    str1=change(str1);
    str2=change(str2);
    list<string> l,l2;
    for(int i=1;i<str1.size();i++){
        if(str1[i]>='a'&&str1[i]<='z'&&str1[i-1]>='a'&&str1[i-1]<='z'){
            string temp="";
            temp+=str1[i-1];
            temp+=str1[i];
            l.push_back(temp);
        }
        else
            continue;
    }
    for (int i = 1; i < str2.size(); i++) {
        if (str2[i] >= 'a' && str2[i] <= 'z' && str2[i-1] >= 'a' && str2[i-1] <= 'z') {
            string temp = "";
            temp += str2[i-1];
            temp += str2[i];
            l2.push_back(temp);
        }
    }
    int hap = l.size() + l2.size();
    int gyo = 0; 
    for (auto it = l2.begin(); it != l2.end(); ) {
        auto found = find(l.begin(), l.end(), *it);
        if (found != l.end()) {
            gyo++;
            hap--; 
            it = l2.erase(it);
            l.erase(found);
        } else {
            ++it;
        }
    }
     if (hap == 0) {
        answer = 65536;
    } else {
        answer = gyo * 65536 / hap;
    }
    return answer;
}