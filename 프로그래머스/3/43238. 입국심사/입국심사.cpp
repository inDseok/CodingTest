#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(),times.end());
    long long s=1,e=(long long)times.back()*n;
    while(s<=e){
        long long mid=(s+e)/2;
        long long t=0;
        for(int i=0;i<times.size();i++){
            t+=(mid/(long long)times[i]);
        }
        if(t>=n){
            e=mid-1;
            answer=mid;
        }
        else{
            s=mid+1;
        }
    }
    return answer;
}