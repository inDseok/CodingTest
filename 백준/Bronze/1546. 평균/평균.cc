#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
   int n;
   int m;
   cin >> n;
   vector<double> v;
   for (int i = 0; i < n; i++) {
       int score;
       cin >> score;
       v.push_back(score);
   }
   sort(v.begin(), v.end());
   m = v[n - 1];
   double sum = 0;
   for (int i = 0; i < n; i++) {
       double new_score = v[i] / m * 100;
       sum += new_score;
   }
   double mean = sum / n;
   cout << mean;
   return 0;
}
