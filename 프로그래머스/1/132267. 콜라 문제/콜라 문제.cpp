#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    while(n>=a){
        int coke;
        coke=n/a*b;
        answer+=coke;
        int temp=n%a;
        n=coke+temp;
    }
    return answer;
}