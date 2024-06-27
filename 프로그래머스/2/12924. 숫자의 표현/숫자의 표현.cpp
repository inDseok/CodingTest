#include <string>
#include <vector>
#include<iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    int s=1;
    while(s<n/2+1){
        int sum=0;
        for(int i=s;i<=n/2+1;i++){
            sum+=i;
            if(sum==n){
                answer++;
                break;
            }
            else if(sum>n)
                break;
        }
        s++;
    }
    answer++;
    return answer;
}