#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> sticker)
{
    int answer =0;
    int s=sticker.size();
    if (s == 1) 
        return sticker[0];

    vector<int> dp1(s,0);
    vector<int> dp2(s,0);
    
    dp1[0]=sticker[0];
    dp1[1]=max(sticker[0],sticker[1]);
    for(int i=2;i<s-1;i++){
        dp1[i]=max(dp1[i-1],dp1[i-2]+sticker[i]);
    }
    dp2[1]=sticker[1];
    for(int i=2;i<s;i++){
        dp2[i]=max(dp2[i-1],dp2[i-2]+sticker[i]);
    }
    answer=max(dp1[s-2],dp2[s-1]);
    return answer;
}