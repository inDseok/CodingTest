#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    for (int i = 1; i < triangle.size(); i++) {
        triangle[i][0]+=triangle[i-1][0];
        triangle[i][i]+=triangle[i-1][i-1];
        for (int j = 1; j < i; j++) {
            triangle[i][j]+=max(triangle[i-1][j-1],triangle[i-1][j]);
        }
    }
    for(int i=0;i<triangle.size();i++){
        answer=max(triangle[triangle.size()-1][i],answer);
    }
    return answer;
}