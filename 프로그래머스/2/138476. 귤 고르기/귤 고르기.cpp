#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool desc(int a,int b){
    return a>b;
}
int solution(int k, vector<int> tangerine) {
    int answer=0;
    vector<int> v(10000001);
    for(int i=0;i<tangerine.size();i++){
        v[tangerine[i]]++;
    }
    sort(v.begin(),v.end(),desc);
    for(int i=0;i<tangerine.size();i++){
        cout<<v[i]<<" ";
    }
    for(int i=0;i<tangerine.size();i++){
        answer++;
        if(k-v[i]>0)
            k-=v[i];
        else
            break;
    }
    return answer;
}