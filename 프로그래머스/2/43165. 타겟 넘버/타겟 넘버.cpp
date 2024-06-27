#include <string>
#include <vector>
int answer = 0;
using namespace std;
void dfs(int cnt, vector<int> numbers,int result , int target)
{
    if(cnt==numbers.size()){
        if(result==target){
            answer++;
        }
        return;
    }
    dfs(cnt+1,numbers,result+numbers[cnt],target);
    dfs(cnt+1,numbers,result-numbers[cnt],target);
}
int solution(vector<int> numbers, int target) {
    dfs(0,numbers,0,target);
    return answer;
}