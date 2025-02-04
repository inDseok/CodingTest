#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v(n+1,0);
    v[0]=1;
    v[1]=1;
    v[2]=2;
    v[3]=5;
    for(int i=4;i<=n;i++){
        for(int j=0;j<i;j++){
            v[i]+=v[j]*v[i-j-1];
        }
    }
    answer=v[n];
    return answer;
}