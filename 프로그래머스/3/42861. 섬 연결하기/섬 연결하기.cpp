#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int arr[101][101]={0};
int visited[101]={0};
int sort_cost(vector<int> a,vector<int> b){
    return a[2]<b[2];
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for(int i=0;i<costs.size();i++){
        arr[costs[i][0]][costs[i][1]]=costs[i][2];
        arr[costs[i][1]][costs[i][0]]=costs[i][2];
    }
    vector<int> v;
    v.push_back(0);
    visited[0]=1;
    while((int)v.size()<=n-1){
        int min_idx;
        int min=9999;
        for(int num : v){
            for(int j=0;j<n;j++){
                if(arr[num][j]==0)
                    continue;
                if(arr[num][j]<min&&!visited[j]){
                    min=arr[num][j];
                    min_idx=j;
                }            
            }
        }
            answer+=min;
            v.push_back(min_idx);
            visited[min_idx]=1;
    }
    return answer;
}