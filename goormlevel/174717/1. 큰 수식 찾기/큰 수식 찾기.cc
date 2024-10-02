#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 수식을 계산하는 함수 (연산자 우선순위 고려)
long long calculateExpression(const string &expr) {
    vector<string> tokens;
    string s = "";
    int expr_size = expr.length();

    // 수식을 파싱하여 숫자와 연산자를 tokens에 저장
    for (int i = 0; i < expr_size; i++) {
        if (expr[i] == '+' || expr[i] == '*' || expr[i] == '-') {
            tokens.push_back(s);  // 이전 숫자를 저장
            tokens.push_back(string(1, expr[i]));  // 연산자 저장
            s = "";  // 임시 문자열 초기화
        } else {
            s += expr[i];
        }
    }
    tokens.push_back(s);  // 마지막 숫자 추가

    // 스택을 사용하여 연산자 우선순위 처리
    stack<long long> values;
    string current_op = "+";  // 첫 번째 숫자는 항상 양수로 처리
    int tokens_size = tokens.size();

    for (int i = 0; i < tokens_size; i++) {
        string token = tokens[i];

        // 숫자일 경우 처리
        if (isdigit(token[0])) {
            long long num = stoll(token);  // 문자열을 long long으로 변환
            
            if (current_op == "+") {
                values.push(num);
            } else if (current_op == "-") {
                values.push(-num);
            } else if (current_op == "*") {
                long long top = values.top();
                values.pop();
                values.push(top * num);
            }
        }
        // 연산자를 만나면 연산자 갱신
        else {
            current_op = token;
        }
    }

    // 스택에 남아 있는 모든 값을 더해 최종 결과 계산
    long long result = 0;
    while (!values.empty()) {
        result += values.top();
        values.pop();
    }

    return result;
}

int main() {
    string a, b;
    cin >> a >> b;

    // 각 수식을 계산
    long long resulta = calculateExpression(a);
    long long resultb = calculateExpression(b);

    // 둘 중 큰 수 출력
    cout << max(resulta, resultb) << endl;

    return 0;
}
