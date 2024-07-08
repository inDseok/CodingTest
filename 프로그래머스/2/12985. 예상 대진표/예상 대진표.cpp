#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
bool min_odd(int a,int b){
    int result=min(a,b);
    if(result%2==0)
        return false;
    return true;
}
int solution(int n, int a, int b)
{
    int answer = 1;
    while(abs(b-a)!=1||!min_odd(a,b)){
        if(a%2!=0)
            a+=1;
        if(b%2!=0)
            b+=1;
        a=a/2;
        b=b/2;
        cout<<a<<" "<<b<<"\n";
        answer++;
    }

    return answer;
}