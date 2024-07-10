#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for(long long i=left;i<=right;i++){
        int col=i%n;
        int row=i/n;
        int temp=max(row,col)+1;
        answer.push_back(temp);
    }
    return answer;
}