#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int> s;
    int n = elements.size();

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < n; ++j) {
            int sum = 0;
            for (int k = j; k < j+i; ++k) {
                sum += elements[k%n];
            }
            s.insert(sum);
        }
    }

    answer = s.size();
    return answer;
}
