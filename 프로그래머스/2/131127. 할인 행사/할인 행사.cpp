#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string,int> m1;
    for(int i=0;i<want.size();i++){
        m1[want[i]]=number[i];
    }
    int start=0;
    int end=10;
   while (end <= discount.size()) {
        map<string, int> m2;
        for (int i = start; i < end; i++) {
            m2[discount[i]] += 1;
        }

        if (m1 == m2) 
            answer++;
        start += 1;
        end += 1;
    }
    return answer;
}