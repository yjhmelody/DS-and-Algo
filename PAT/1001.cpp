#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
  int a, b, sum;
  cin >> a >> b;
  sum = a + b;
  string str;
  stringstream ss;
  ss << sum;
  ss >> str;

  string str_sum;
  for (int i = str.length()-1, n = 1; i >= 0; i--, n++) {
    str_sum.append(&str[i], 1);
    if (n == 3) {
      n = 0;
      if (str[i-1] != '-') {
        str_sum.append(",");
      }
    }
  }

  int i = str_sum[str_sum.length()-1] != ',' ? str_sum.length()-1 : str_sum.length()-2;
  for (; i >= 0; i--) {
    cout << str_sum[i];
  }
  cout << endl;
  return 0;
}
