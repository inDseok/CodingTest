#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int,int> old,young;
    for(int i : topping){
        young[i]++;
    }
    for(int i : topping){
        old[i]++;
        young[i]--;
        if(young[i]==0){
            young.erase(i);
        }
        if(old.size()==young.size())
            answer++;
    }
    return answer;
}