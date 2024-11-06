#include<iostream>
#include<vector>
using namespace std;

int n, k;
vector<int> d;
vector<bool> r;

void beltmove() {
    int back_value = d.back();
    bool back_robot = r.back();
    d.pop_back();
    r.pop_back();
    d.insert(d.begin(), back_value);
    r.insert(r.begin(), back_robot);
    r[n - 1] = false;
}

void robotmove() 
{
    for (int i = n - 1; i >= 0; i--) {
        if (r[i] == true && (r[i + 1] == false && d[i + 1] > 0)) {
            r[i] = false;
            r[i + 1] = true;
            d[i + 1]--;
        }
    }
    r[n - 1] = false;
}

void put_robot() {
    if (!r[0] && d[0] > 0) {
        r[0] = true;
        d[0]--;
    }
}

int check() {
    int cnt = 0;
    for (int i = 0; i < d.size(); i++) {
        if (d[i] == 0)
            cnt++;
    }
    return cnt;
}

int main() {
    cin >> n >> k;
    d.resize(2 * n);
    r.resize(2 * n, false);

    for (int i = 0; i < 2 * n; i++) {
        cin >> d[i];
    }

    int result = 0;
    while (true) {
        result++;
        beltmove();
        robotmove();
        put_robot();
        if (check() >= k) {
            cout << result;
            break;
        }
    }

    return 0;
}
