#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool desc(vector<int> a,vector<int> b){
    return a[1]<b[1];
}
int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(),routes.end(),desc);
    int cur=routes[0][1];
    answer++;
    for(int i=1;i<routes.size();i++){
        if(cur<routes[i][0]){
            answer++;
            cur=routes[i][1];
        }
    }
    return answer;
}