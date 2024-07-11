#include <string>
#include <vector>
#include <set>
using namespace std;

bool solution(vector<string> phone_book) {
    set<string> s;
    
    for(const string& number : phone_book) {
        s.insert(number);
    }
    
    for(const string& number : phone_book) {
        for(int i = 1; i < number.size(); i++) {
            if(s.find(number.substr(0, i)) != s.end()) {
                return false;
            }
        }
    }
    
    return true;
}
