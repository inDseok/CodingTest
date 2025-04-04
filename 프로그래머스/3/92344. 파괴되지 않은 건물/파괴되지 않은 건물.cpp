#include <string>
#include <vector>
#include <iostream>
using namespace std;
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    vector<vector<int>> diff(board.size()+3,vector<int>(board.size()+3,0));
    for(auto temp : skill){
        if(temp[0]==1){
            diff[temp[1]+1][temp[2]+1]-=temp[5]; //좌상
            diff[temp[1]+1][temp[4]+2]+=temp[5]; //우상
            diff[temp[3]+2][temp[2]+1]+=temp[5]; //좌하
            diff[temp[3]+2][temp[4]+2]-=temp[5]; //우하
        }
        else{
            diff[temp[1]+1][temp[2]+1]+=temp[5]; //좌상
            diff[temp[1]+1][temp[4]+2]-=temp[5]; //우상
            diff[temp[3]+2][temp[2]+1]-=temp[5]; //좌하
            diff[temp[3]+2][temp[4]+2]+=temp[5]; //우하
        }
    }
    for(int i=1;i<diff.size();i++){
        for(int j=1;j<diff[i].size();j++){
            diff[i][j]+=diff[i][j-1];
        }
    }
    for(int i=1;i<diff.size();i++){
        for(int j=1;j<diff[i].size();j++){
            diff[i][j]+=diff[i-1][j];
        }
    }
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            board[i][j]+=diff[i+1][j+1];
            if(board[i][j]>0)
                answer++;
        }
    }
    return answer;
}