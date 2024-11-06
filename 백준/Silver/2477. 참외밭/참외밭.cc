#include<iostream>
using namespace std;

typedef struct {
    int x, y;
}square;

int main() {

    int k, a, b, res_a = 0, res_b = 0, x = 0, y = 0;
    cin >> k;
    square square[7];

    for (int i = 0; i < 6; i++) {
        cin >> a >> b;
        switch (a) {
        case 1:
            x += b;
            break;
        case 2:
            x -= b;
            break;
        case 3:
            y -= b;
            break;
        case 4:
            y += b;
            break;
        }
        square[i].x = x;
        square[i].y = y;
    }
    square[6] = square[0];
    for (int i = 0; i < 6; i++) {
        res_a += square[i].x * square[i + 1].y;
        res_b += square[i].y * square[i + 1].x;
    }
    int res = (abs(res_a - res_b) / 2) * k;
    printf("%d", res);
    return 0;
}