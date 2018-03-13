#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>

using namespace std;

/**
    1 1 1
    2 1 1 0 1

    2 2 1.0 1 1.0
*/

int main() {
  int k1, k2;

  cin >> k1;
  vector<pair<int, double>> poly1(k1);
  for (auto &x: poly1) {
    cin >> x.first;
    cin >> x.second;
  }

  cin >> k2;
  vector<pair<int, double>> poly2(k2);
  for (auto &x: poly2) {
    cin >> x.first;
    cin >> x.second;
  }

  // 最大指数
  int maxN = poly1[0].first + poly2[0].first;
  vector<pair<int, double>> poly3(maxN+1);
  for(auto &x: poly1) {
    for(auto &y: poly2) {
        poly3[x.first + y.first].second += x.second * y.second;
    }
  }
  int count = 0;
  for(auto &x: poly3) {
    if(x.second != 0)
        count++;
  }
  cout << count;
  int i = maxN;
  for(auto it = poly3.rbegin(); it != poly3.rend(); it++, i--) {
    if(it->second == 0)
        continue;
    printf(" %d %.1f", i, it->second);
  }
  cout << endl;
  return 0;
}
