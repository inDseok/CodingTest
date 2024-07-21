#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    vector<int> v(money.size()+1);
    vector<int> v2(money.size()+1);
    v[0]=money[0];
    v[1]=max(money[1],money[0]);
    for(int i=2;i<money.size()-1;i++){
        v[i]=max(v[i-2]+money[i],v[i-1]);
    }
    v2[0]=0;
    v2[1]=money[1];
    for(int i=2;i<=money.size()-1;i++){
        v2[i]=max(v2[i-2]+money[i],v2[i-1]);
    }
    answer=max(v[money.size()-2],v2[money.size()-1]);
    return answer;
}