#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<map>

using namespace std;

vector<string> digits = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
};

int main() {
    string num;
    cin >> num;
    int sum = 0;
    for(auto it = num.cbegin(); it != num.cend(); it++) {
        const char s = *it;
        sum += atoi(&s);
    }
    stack<int> stk;
    if(sum == 0) {
        stk.push(0);
    }
    while(sum) {
        stk.push(sum % 10);
        sum /= 10;
    }
    while(stk.size() != 1) {
        cout << digits[stk.top()] << " ";
        stk.pop();
    }
    cout << digits[stk.top()] << endl;
    return 0;
}
