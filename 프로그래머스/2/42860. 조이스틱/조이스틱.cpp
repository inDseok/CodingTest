#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int num[26]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1};
int solution(string name) {
    int answer = 0;
    string s="";
    int n=name.size();
    int min_move=name.size()-1;
    for(int i=0;i<name.size();i++){
        answer+=num[name[i]-'A'];
        int j = i+1;
        while(j<name.size()&&name[j]=='A')
            j++;
        min_move = min(min_move, i + n - j + min(i, n - j));
    }
    answer+=min_move;
    return answer;
}