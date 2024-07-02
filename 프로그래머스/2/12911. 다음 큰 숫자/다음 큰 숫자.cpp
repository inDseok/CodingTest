#include <string>
#include <vector>

using namespace std;
int count_one(int a){
    int one=0;
    while(a){
        if(a%2==1)
            one++;
        a/=2;
    }
    return one;
}
int solution(int n) {
    int answer = 0;
    int one=0;
    one=count_one(n);
    int ln=n+1;
    while(1){
        if(one==count_one(ln)){
            break;
        }
        ln+=1;
    }
    answer=ln;
    return answer;
}