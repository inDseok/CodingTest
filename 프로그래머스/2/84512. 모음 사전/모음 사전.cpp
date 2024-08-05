#include <string>
#include <vector>

using namespace std;
int answer = 0;
int cnt=-1;
string w;
string aeiou="AEIOU";
void dfs(string s){
    cnt++;
    if(s==w){
        answer=cnt;
        return;
    }
    if(s.size()>=5)
        return;
    for(int i=0;i<aeiou.size();i++){
        dfs(s+aeiou[i]);
    }
}
int solution(string word) {
    w=word;
    dfs("");
    return answer;
}