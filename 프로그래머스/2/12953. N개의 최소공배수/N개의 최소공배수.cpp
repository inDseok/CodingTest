#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    for(int i=1;i<arr.size();i++){
        arr[i]=arr[i-1]*arr[i]/__gcd(arr[i-1],arr[i]);
    }
    answer=arr[(int)arr.size()-1];
    return answer;
}