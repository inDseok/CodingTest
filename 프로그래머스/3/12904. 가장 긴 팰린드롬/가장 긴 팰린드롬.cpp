#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
    int answer=0;
    for(int i=0;i<s.size();i++){
        //홀수개수
        int length=1;
        int left=i-1;
        int right=i+1;
        while(left>=0&&right<s.size()&&s[left--]==s[right++]){
            length+=2;
        }
        answer=max(answer,length);
        //짝수 개수
        length=0;
        left=i-1;
        right=i;
        while(left>=0&&right<s.size()&&s[left--]==s[right++]){
            length+=2;
        }
        answer=max(answer,length);
    }
    return answer;
}