#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <set>
using namespace std;
bool isPrime(int a){
    if(a<=1)
        return false;
    for(int i=2;i<=sqrt(a);i++){
        if(a%i==0){
            return false;
        }
    }
    return true;
}
int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(),numbers.end());
    set<int> s;
    do{
        for(int i=1;i<=numbers.size();i++){
            string num=numbers.substr(0,i);
            if(isPrime(stoi(num))){
                s.insert(stoi(num));
            }   
        }
    }while(next_permutation(numbers.begin(),numbers.end()));
    answer=s.size();
    return answer;
}