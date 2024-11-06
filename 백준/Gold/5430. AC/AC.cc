#include <iostream>
#include <string>
#include <deque>

using namespace std;

void reverseQueue(deque<int>& q) {
    deque<int> temp;
    while (!q.empty()) {
        temp.push_front(q.front());
        q.pop_front();
    }
    q.swap(temp);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string p;
        cin >> p;

        int n;
        cin >> n;

        deque<int> num;
        string input;
        cin >> input;

        int index = 0;
        string snum;

        // 입력 받은 문자열을 숫자로 변환하여 덱에 저장
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '[') {
                continue;
            }
            else if (input[i] == ',' || input[i] == ']') {
                if (snum != "") {
                    num.push_back(stoi(snum));
                    snum = "";
                    index++;
                }
            }
            else {
                snum += input[i];
            }
        }

        bool R = false;
        bool error = false;

        // 연산 수행
        for (int i = 0; i < p.size(); i++) {
            if (p[i] == 'R') {
                R = !R;
            }
            else if (p[i] == 'D') {
                if (num.empty()) {
                    error = true;
                    break;
                }
                else {
                    if (R)
                        num.pop_back();
                    else
                        num.pop_front();
                }
            }
        }

        // 결과 출력
        if (error) {
            cout << "error\n";
        }
        else {
            cout << "[";
            if (!num.empty()) {
                if (R)
                    reverseQueue(num);
                cout << num.front();
                num.pop_front();
                while (!num.empty()) {
                    cout << "," << num.front();
                    num.pop_front();
                }
            }
            cout << "]\n";
        }
    }
    return 0;
}
