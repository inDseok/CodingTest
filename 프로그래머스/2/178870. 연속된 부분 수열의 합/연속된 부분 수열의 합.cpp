#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int li=0,hi=0;
    int sum=sequence[0];
    while(li<=hi&&hi<sequence.size()){
        if(sum==k){
            if(answer.empty()||answer[1]-answer[0]>hi-li){
                answer={li,hi};
            }
        }
        if(sum<k){
            hi++;
            sum+=sequence[hi];
        }
        else{
            sum-=sequence[li];
            li++;
        }
    }
    return answer;
}