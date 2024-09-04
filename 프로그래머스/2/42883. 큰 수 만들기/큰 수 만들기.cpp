#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int size=number.size()-k;
    int idx=0;
    for(int i=0;i<size;i++){
        char maxnum=number[idx];
        int maxidx=idx;
        for(int j=idx;j<=k+i;j++){
            if(maxnum<number[j]){
                maxnum=number[j];
                maxidx=j;
            }
        }
        idx=maxidx+1;
        answer+=maxnum;
    }
    return answer;
}