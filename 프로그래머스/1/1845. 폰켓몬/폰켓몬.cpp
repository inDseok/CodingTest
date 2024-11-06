#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> s;
    for(int i=0;i<nums.size();i++){
        s.insert(nums[i]);
    }
    int n=nums.size();
    if(n/2>s.size())
        answer=s.size();
    else{
        answer=n/2;
    }
    return answer;
}