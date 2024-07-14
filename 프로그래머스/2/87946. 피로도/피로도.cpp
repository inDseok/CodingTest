#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    sort(dungeons.begin(),dungeons.end());
    do{
        int temp=k;
        int m=0;
        for(int i=0;i<dungeons.size();i++){
            if(temp>=dungeons[i][0]){
                temp-=dungeons[i][1];
                m++;
            }
            else{
                break;
            }
            answer=max(answer,m);
        }
    }while(next_permutation(dungeons.begin(),dungeons.end()));
    return answer;
}