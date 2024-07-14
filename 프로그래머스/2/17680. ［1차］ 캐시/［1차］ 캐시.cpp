#include <string>
#include <vector>
#include <unordered_set>
#include <list>
#include <string>
#include <iostream>
using namespace std;
string change(string a){
    string result="";
    for(int i=0;i<a.size();i++){
        result+=tolower(a[i]);
    }
    return result;
}
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    unordered_set<string> s;
    list<string> cache;
    if (cacheSize == 0) {
        answer=cities.size() * 5;
        return answer;
    }
    for(string city : cities){
        city=change(city);
        if(s.find(city)!=s.end()){
            cache.remove(city);
            answer+=1;
        }
        else{
            answer+=5;
            if(cache.size()==cacheSize){
                s.erase(cache.back());
                cache.pop_back();
            }
        }
        cache.push_front(city);
        s.insert(city);
    }
    return answer;
}