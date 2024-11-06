#include<iostream>
#include<map>;
using namespace std;
string s;
map<string,int> m;
string sp;
int main()
{
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        sp = "";
        for (int j = i; j < s.size(); j++) {
            sp += s[j];
            m[sp] = 1;
        }
    }
    cout << m.size();
}