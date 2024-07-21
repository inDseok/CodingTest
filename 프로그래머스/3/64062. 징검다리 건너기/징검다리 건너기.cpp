#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    int left=*min_element(stones.begin(),stones.end());
    int right=*max_element(stones.begin(),stones.end());
    while(left<=right){
        int mid=(left+right)/2;
        int cnt=0;
        for(int i=0;i<stones.size();i++){
            if(stones[i]-mid<=0)
                cnt++;
            else
                cnt=0;
            if(cnt==k)
                break;
        }
        if(cnt!=k)
            left=mid+1;
        else
            right=mid-1;
    }
    answer=left;
    return answer;
}