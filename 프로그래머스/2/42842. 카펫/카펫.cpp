#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum=brown+yellow;
    for(int i=3;i<=sum;i++){
        for(int j=3;j<=i;j++){
            if(i*j==sum){
                for(int k=1;k<=j/2+1;k++){
                    if((i-k)*(j-k)==yellow){
                        answer.push_back(i);
                        answer.push_back(j);
                        return answer;
                    }
                }
            }
        }
    }
    return answer;
}