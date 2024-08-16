#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int storey) {
    int answer = 0;
    while(storey>0){
        int num=storey%10;
        if(num>5||(num==5&&(storey-num)/10%10>=5)){
            storey+=10-num;
            answer+=10-num;
        }
        else{
            storey-=num;
            answer+=num;
        }
        cout<<storey<<"\n";
        storey/=10;
    }
    return answer;
}