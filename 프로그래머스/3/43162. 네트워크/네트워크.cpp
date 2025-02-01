#include <string>
#include <vector>
#include <iostream>
using namespace std;
int arr[201][201];
bool visited[201];
void dfs(int n,int cur,vector<vector<int>> computers){
    for(int i=0;i<n;i++){
        if(computers[cur][i]==1&&visited[i]==false){
            visited[i]=true;
            dfs(n,i,computers);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            visited[i]=true;
            dfs(n,i,computers);
            answer++;
        }
    }
    return answer;
}