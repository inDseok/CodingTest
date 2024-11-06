#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double a, b;
    cin >> a >> b;
    double c = a / b;

    // 소수점 아래 9자리 이상을 출력하도록 설정
    cout << fixed << setprecision(10) << c << endl;

    return 0;
}
