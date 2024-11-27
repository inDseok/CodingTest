#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    unordered_set<char> skipset(skip.begin(),skip.end());
    for(char c:s){
        int count=0;
        char current=c;
        while(count<index){
            current++;
            if(current>'z')
                current='a';
            if(skipset.find(current)==skipset.end())
                count++;
        }    
        answer+=current;
    }
    return answer;
}