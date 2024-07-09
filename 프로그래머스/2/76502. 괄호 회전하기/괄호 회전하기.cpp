#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;
    int k=0;
    int cnt=(int)s.size();
    while(cnt--){
        stack<char> st;
        bool chk=true;
        for(int i=0;i<s.size();i++){
            if(s[i]=='{'||s[i]=='['||s[i]=='(')
                st.push(s[i]);
            else{
                if(st.empty()){
                    chk=false;
                    break;
                }
                char top=st.top();
                if ((s[i] == '}' && top == '{') ||
                    (s[i] == ']' && top == '[') ||
                    (s[i] == ')' && top == '(')) {
                    st.pop();
                }
                else {
                    chk = false;
                    break;
                }
            }
        }
        if(chk&&st.empty())
            answer++;
        s = s.substr(1) + s[0];
    }
    return answer;
}