#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int start = 0;
    int total = 0;
    while (1) {
        for (int i = start; i < progresses.size(); i++) {
            progresses[i] += speeds[i];
        }
        if (progresses[start] >= 100) {
            int cnt = 0;
            while (start < progresses.size() && progresses[start] >= 100) {
                cnt++;
                start++;
            }
            total += cnt;
            answer.push_back(cnt);
        }
        if (total == progresses.size())
            break;
    }
    return answer;
}
