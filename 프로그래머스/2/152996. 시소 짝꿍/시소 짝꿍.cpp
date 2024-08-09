#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    map<int,long long> m;
    for(int num : weights){
        if(m.find(num)!=m.end()){
            m[num]++;
        }
        else{
            m.insert({num,1});
        }
    }
    for(int i=0;i<weights.size();i++){
        int temp=weights[i]*2;
        if(temp%3==0&&m.find(temp/3)!=m.end()){
            answer+=m[temp/3];
        }
        if(temp%4==0&&m.find(temp/4)!=m.end()){
            answer+=m[temp/4];
        }
        temp=weights[i]*3;
        if(temp%4==0&&m.find(temp/4)!=m.end()){
            answer+=m[temp/4];
        }
    }
    for(auto it=m.begin();it!=m.end();it++){
        if(it->second>=2){
            long long t=it->second*(it->second-1)/2;
            answer+=t;
        }
    }
    return answer;
}
