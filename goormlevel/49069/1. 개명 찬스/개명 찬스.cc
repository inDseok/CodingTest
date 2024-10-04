#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    cin >> name;
    int n = name.size();

    for (int i = 0; i < n - 1; i++) {
        if (name[i] > name[i + 1]) {
            cout << name.substr(0, i) + name.substr(i + 1) << "\n";
            return 0;
        }
    }

    // If no character was found to be greater, remove the last character
    cout << name.substr(0, n - 1) << "\n";
    return 0;
}
