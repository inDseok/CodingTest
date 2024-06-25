#include <string>
#include <vector>
#include<iostream>
using namespace std;
#define mod 1000000007;
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> v(n+1,vector<int>(m+1,0));
    v[1][1]=1;
    for(int i=0;i<puddles.size();i++){
        int col=puddles[i][0];
        int row=puddles[i][1];
        v[row][col]=-1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(v[i][j]==-1){
                v[i][j]=0;
                continue;
            }
            else{
                if (i > 1) v[i][j] += v[i - 1][j];
                if (j > 1) v[i][j] += v[i][j - 1];
                v[i][j] %= mod;
            }
        }
    }
    answer=v[n][m];
    return answer;
}